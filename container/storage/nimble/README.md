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

透過nlt設定group權限

```
nltadm --group --add --ip-address 192.168.182.11 --username admin
nltadm --group --verify --ip-address 192.168.182.11
nltadm --status
```

新增 Docker Volume

```
docker volume create -d nimble mytestvol
```



