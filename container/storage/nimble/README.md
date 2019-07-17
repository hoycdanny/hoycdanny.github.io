Docker Containers - Nimble Storage install

此手冊為Nimble Docker Volume安裝步驟

* 安裝所需的套件

```bash
yum install -y sg3_utils device-mapper-persistent-data device-mapper-multipath lvm2 iscsi-initiator-utils yum-utils
systemctl daemon-reload
systemctl enable iscsid multipathd
systemctl start iscsid multipathd
```

* 安裝NLT 3.0.0.26

```
wget https://infosight.hpe.com/InfoSight/media/software/active/public/17/247/nlt_installer_3.0.0.26?accepted_eula=yes&confirm=Download
sh nlt_installer_3.0.0.26
```

* 安裝Docker

```
yum-config-manager --add-repo  
https://download.docker.com/linux/centos/docker-ce.repo
yum install -y docker-ce-17.06.1.ce
systemctl start docker
systemctl enable docker
```

* 設定Nimble Plugin config

```
docker plugin install --disable --grant-all-permissions --alias nimble store/nimblestorage/nimble:2.1.1
docker plugin set nimble ip=192.168.182.11 username=admin password=P@ssw0rd
docker plugin enable nimble
```

* 透過nlt設定group權限

```
nltadm --group --add --ip-address 192.168.182.11 --username admin
nltadm --group --verify --ip-address 192.168.182.11
nltadm --status
```

* 新增 Docker Volume

```
docker volume create -d nimble mytestvol
```

* 安裝Dory

```
wget https://github.com/hpe-storage/python-hpedockerplugin/raw/master/dory_installer_v31
chmod u+x ./dory_installer_v31
./dory_installer_v31
ls -l /usr/libexec/kubernetes/kubelet-plugins/volume/exec/hpe.com~hpe/
cp -R /usr/libexec/kubernetes/kubelet-plugins/volume/exec/hpe.com~hpe/ /var/lib/kubelet/volumeplugins/
```

* create file ds-doryd.yaml

```
---
apiVersion: extensions/v1beta1
kind: DaemonSet
metadata:
  name: doryd
spec:
  updateStrategy:
     type: RollingUpdate
  template:
    metadata:
      namespace: kube-system
      labels:
        daemon: dory-daemon
      name: doryd
    spec:
      restartPolicy: Always
      tolerations:
       -
          effect: NoSchedule
          operator: Exists
      containers:
        -
          image: nimblestorage/doryd
          imagePullPolicy: Always
          name: dory
          volumeMounts:
             - name: k8s
               mountPath: /etc/kubernetes
             - name: flexvolumedriver
               mountPath: /usr/libexec/kubernetes/kubelet-plugins/volume/exec
             - name: dockersocket
               mountPath: /run/docker/plugins/
      volumes:
        - name: k8s
          hostPath:
             path: /etc/kubernetes/
        - name: flexvolumedriver
          hostPath:
             path: /usr/libexec/kubernetes/kubelet-plugins/volume/exec
        - name: dockersocket
          hostPath:
              path: /run/docker/plugins/
```

* create DaemonSet

```
kubectl create -f ds-doryd.yaml
```

* create file sc-transactionaldb.yml

```
---
kind: StorageClass
apiVersion: storage.k8s.io/v1
metadata:
 name: transactionaldb
provisioner: dev.hpe.com/nimble
parameters:
  description: "Volume provisioned by doryd from transactionaldb StorageClass"
  perfPolicy: "SQL Server"
  protectionTemplate: "Retain-48Hourly-30Daily-52Weekly"
```

* create storage class

```
kubectl create -f sc-transactionaldb.yml
```

* create file pvc-example.yml

```
---
apiVersion: v1
kind: PersistentVolumeClaim
metadata:
  name: example-claim
spec:
  accessModes:
    - ReadWriteOnce
  resources:
    requests:
      storage: 16Gi
  storageClassName: transactionaldb
```

* create Persistent Volume Claim

```
kubectl create -f pvc-example.yml
```

![](/container/storage/nimble/images/result.png)

