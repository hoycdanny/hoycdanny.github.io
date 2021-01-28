# HPE Ezmeral Data Fabric CSI

## 設定CSI環境

```
apiVersion: v1
kind: Namespace
metadata:
  name: mapr-csi
  labels:
    name: mapr-csi

---
apiVersion: v1
kind: ServiceAccount
metadata:
  name: csi-nodeplugin-sa
  namespace: mapr-csi

---
kind: ClusterRole
apiVersion: rbac.authorization.k8s.io/v1
metadata:
  name: csi-nodeplugin-cr
  namespace: mapr-csi
rules:
  - apiGroups: [""]
    resources: ["secrets"]
    verbs: ["get", "list"]
  - apiGroups: [""]
    resources: ["nodes"]
    verbs: ["get", "list", "update"]
  - apiGroups: [""]
    resources: ["namespaces"]
    verbs: ["get", "list"]
  - apiGroups: [""]
    resources: ["persistentvolumes"]
    verbs: ["get", "list", "watch", "update"]
  - apiGroups: ["storage.k8s.io"]
    resources: ["storageclasses"]
    verbs: ["get", "list", "watch"]

---
kind: ClusterRoleBinding
apiVersion: rbac.authorization.k8s.io/v1
metadata:
  name: csi-nodeplugin-crb
  namespace: mapr-csi
subjects:
  - kind: ServiceAccount
    name: csi-nodeplugin-sa
    namespace: mapr-csi
roleRef:
  kind: ClusterRole
  name: csi-nodeplugin-cr
  apiGroup: rbac.authorization.k8s.io

---
apiVersion: v1
kind: ServiceAccount
metadata:
  name: csi-controller-sa
  namespace: mapr-csi

---
kind: ClusterRole
apiVersion: rbac.authorization.k8s.io/v1
metadata:
  name: csi-attacher-cr
  namespace: mapr-csi
rules:
  - apiGroups: [""]
    resources: ["secrets"]
    verbs: ["get", "list"]
  - apiGroups: [""]
    resources: ["events"]
    verbs: ["get", "list", "watch", "update"]
  - apiGroups: [""]
    resources: ["persistentvolumes"]
    verbs: ["get", "list", "watch", "update"]
  - apiGroups: [""]
    resources: ["nodes"]
    verbs: ["get", "list", "watch"]
  - apiGroups: ["storage.k8s.io"]
    resources: ["volumeattachments"]
    verbs: ["get", "list", "watch", "update"]

---
kind: ClusterRoleBinding
apiVersion: rbac.authorization.k8s.io/v1
metadata:
  name: csi-attacher-crb
  namespace: mapr-csi
subjects:
  - kind: ServiceAccount
    name: csi-controller-sa
    namespace: mapr-csi
roleRef:
  kind: ClusterRole
  name: csi-attacher-cr
  apiGroup: rbac.authorization.k8s.io

---
kind: ClusterRole
apiVersion: rbac.authorization.k8s.io/v1
metadata:
  name: csi-controller-cr
  namespace: mapr-csi
rules:
  - apiGroups: [""]
    resources: ["secrets"]
    verbs: ["get", "list"]
  - apiGroups: [""]
    resources: ["persistentvolumes"]
    verbs: ["get", "list", "watch", "create", "delete"]
  - apiGroups: [""]
    resources: ["persistentvolumeclaims"]
    verbs: ["get", "list", "watch", "update"]
  - apiGroups: ["storage.k8s.io"]
    resources: ["storageclasses"]
    verbs: ["get", "list", "watch"]
  - apiGroups: [""]
    resources: ["events"]
    verbs: ["list", "watch", "update", "create", "patch"]
  - apiGroups: [""]
    resources: ["nodes"]
    verbs: ["get", "list", "update"]
  - apiGroups: ["snapshot.storage.k8s.io"]
    resources: ["volumesnapshotclasses"]
    verbs: ["get", "list", "watch"]
  - apiGroups: ["snapshot.storage.k8s.io"]
    resources: ["volumesnapshotcontents"]
    verbs: ["create", "get", "list", "watch", "update", "delete"]
  - apiGroups: ["snapshot.storage.k8s.io"]
    resources: ["volumesnapshots"]
    verbs: ["get", "list", "watch", "update"]
  - apiGroups: ["apiextensions.k8s.io"]
    resources: ["customresourcedefinitions"]
    verbs: ["create", "list", "watch", "delete"]

---
kind: ClusterRoleBinding
apiVersion: rbac.authorization.k8s.io/v1
metadata:
  name: csi-controller-crb
  namespace: mapr-csi
subjects:
  - kind: ServiceAccount
    name: csi-controller-sa
    namespace: mapr-csi
roleRef:
  kind: ClusterRole
  name: csi-controller-cr
  apiGroup: rbac.authorization.k8s.io

---
kind: DaemonSet
apiVersion: apps/v1beta2
metadata:
  name: csi-nodeplugin-kdf
  namespace: mapr-csi
spec:
  selector:
    matchLabels:
      app: csi-nodeplugin-kdf
  template:
    metadata:
      labels:
        app: csi-nodeplugin-kdf
    spec:
      serviceAccount: csi-nodeplugin-sa
      hostNetwork: true
      containers:
        - name: csi-node-driver-registrar
          image: quay.io/k8scsi/csi-node-driver-registrar:v1.0.1
          imagePullPolicy: "Always"
          args:
            - "--v=5"
            - "--csi-address=$(ADDRESS)"
            - "--kubelet-registration-path=/var/lib/kubelet/plugins/com.mapr.csi-kdf/csi.sock"
          lifecycle:
            preStop:
              exec:
                command: ["/bin/sh", "-c", "rm -rf /registration/com.mapr.csi-kdf /registration/com.mapr.csi-kdf-reg.sock"]
          env:
            - name: ADDRESS
              value: /plugin/csi.sock
            - name: KUBE_NODE_NAME
              valueFrom:
                fieldRef:
                  fieldPath: spec.nodeName
          volumeMounts:
            - name: plugin-dir
              mountPath: /plugin
            - name: registration-dir
              mountPath: /registration/
        - name: liveness-probe
          image: quay.io/k8scsi/livenessprobe:v1.0.2
          imagePullPolicy: "Always"
          args:
            - "--v=5"
            - "--csi-address=$(ADDRESS)"
            - "--connection-timeout=60s"
            - "--health-port=9808"
          env:
            - name: ADDRESS
              value: /plugin/csi.sock
          volumeMounts:
            - name: plugin-dir
              mountPath: /plugin
        - name: mapr-kdfplugin
          securityContext:
            privileged: true
            capabilities:
              add: ["SYS_ADMIN"]
            allowPrivilegeEscalation: true
          image: maprtech/csi-kdfplugin:1.0.0_centos7
          imagePullPolicy: "Always"
          args :
            - "--nodeid=$(NODE_ID)"
            - "--endpoint=$(CSI_ENDPOINT)"
            - "--maxvolumepernode=20"
            - "-v=5"
          env:
            - name: NODE_ID
              valueFrom:
                fieldRef:
                  fieldPath: spec.nodeName
            - name: CSI_ENDPOINT
              value: unix://plugin/csi.sock
          ports:
          - containerPort: 9808
            name: healthz
            protocol: TCP
          livenessProbe:
            failureThreshold: 20
            httpGet:
              path: /healthz
              port: healthz
            initialDelaySeconds: 10
            timeoutSeconds: 3
            periodSeconds: 5
          volumeMounts:
            - name: plugin-dir
              mountPath: /plugin
            - name: pods-mount-dir
              mountPath: /var/lib/kubelet/pods
              mountPropagation: Bidirectional
            - name: k8s-log-dir
              mountPath: /var/log/csi-maprkdf
            - name: timezone
              mountPath: /etc/localtime
              readOnly: true
      volumes:
        - name: plugin-dir
          hostPath:
            path: /var/lib/kubelet/plugins/com.mapr.csi-kdf
            type: DirectoryOrCreate
        - name: registration-dir
          hostPath:
            path: /var/lib/kubelet/plugins_registry
            type: Directory
        - name: pods-mount-dir
          hostPath:
            path: /var/lib/kubelet/pods
            type: Directory
        - name: k8s-log-dir
          hostPath:
            path: /var/log/csi-maprkdf
            type: DirectoryOrCreate
        - name: timezone
          hostPath:
            path: /etc/localtime

---
kind: StatefulSet
apiVersion: apps/v1beta1
metadata:
  name: csi-controller-kdf
  namespace: mapr-csi
spec:
  serviceName: "kdf-provisioner-svc"
  replicas: 1
  template:
    metadata:
      labels:
        app: csi-controller-kdf
    spec:
      serviceAccount: csi-controller-sa
      containers:
        - name: csi-attacher
          image: quay.io/k8scsi/csi-attacher:v1.0.1
          args:
            - "--v=5"
            - "--csi-address=$(ADDRESS)"
          env:
            - name: ADDRESS
              value: /var/lib/csi/sockets/pluginproxy/csi.sock
          imagePullPolicy: "Always"
          volumeMounts:
            - name: socket-dir
              mountPath: /var/lib/csi/sockets/pluginproxy/
        - name: csi-provisioner
          image: quay.io/k8scsi/csi-provisioner:v1.0.1
          args:
            - "--provisioner=com.mapr.csi-kdf"
            - "--csi-address=$(ADDRESS)"
            - "--volume-name-prefix=mapr-pv"
            - "--v=5"
          env:
            - name: ADDRESS
              value: /var/lib/csi/sockets/pluginproxy/csi.sock
          imagePullPolicy: "Always"
          volumeMounts:
            - name: socket-dir
              mountPath: /var/lib/csi/sockets/pluginproxy/
        - name: csi-snapshotter
          image: quay.io/k8scsi/csi-snapshotter:v1.0.1
          imagePullPolicy: "Always"
          args:
            - "--snapshotter=com.mapr.csi-kdf"
            - "--csi-address=$(ADDRESS)"
            - "--snapshot-name-prefix=mapr-snapshot"
            - "--v=5"
          env:
            - name: ADDRESS
              value: /var/lib/csi/sockets/pluginproxy/csi.sock
          volumeMounts:
            - name: socket-dir
              mountPath: /var/lib/csi/sockets/pluginproxy/
        - name: liveness-probe
          image: quay.io/k8scsi/livenessprobe:v1.0.2
          imagePullPolicy: "Always"
          args:
            - "--v=5"
            - "--csi-address=$(ADDRESS)"
            - "--connection-timeout=60s"
            - "--health-port=9809"
          env:
            - name: ADDRESS
              value: /var/lib/csi/sockets/pluginproxy/csi.sock
          volumeMounts:
            - name: socket-dir
              mountPath: /var/lib/csi/sockets/pluginproxy/
        - name: mapr-kdfprovisioner
          image: maprtech/csi-kdfprovisioner:1.0.0
          imagePullPolicy: "Always"
          args :
            - "--nodeid=$(NODE_ID)"
            - "--endpoint=$(CSI_ENDPOINT)"
            - "-v=5"
          env:
            - name: NODE_ID
              valueFrom:
                fieldRef:
                  fieldPath: spec.nodeName
            - name: CSI_ENDPOINT
              value: unix://plugin/csi.sock
          ports:
          - containerPort: 9809
            name: healthz
            protocol: TCP
          livenessProbe:
            failureThreshold: 20
            httpGet:
              path: /healthz
              port: healthz
            initialDelaySeconds: 10
            timeoutSeconds: 3
            periodSeconds: 5
          volumeMounts:
            - name: socket-dir
              mountPath: /plugin
            - name: k8s-log-dir
              mountPath: /var/log/csi-maprkdf
            - name: timezone
              mountPath: /etc/localtime
              readOnly: true
      volumes:
        - name: socket-dir
          emptyDir: {}
        - name: k8s-log-dir
          hostPath:
            path: /var/log/csi-maprkdf
            type: DirectoryOrCreate
        - name: timezone
          hostPath:
            path: /etc/localtime

```


```
apiVersion: v1
kind: Namespace
metadata:
  name: test-csi
  labels:
    name: test-csi

---
apiVersion: v1
kind: Secret
metadata:
  name: mapr-ticket-secret
  namespace: test-csi
type: Opaque
data:
  MAPR_CLUSTER_USER: bWFwcg==
  MAPR_CLUSTER_PASSWORD: bWFwcg==
  CONTAINER_TICKET: bXkuY2x1c3Rlci5jb20gTDBBS1hkWHNITlBFbG81QlM1R2NWY0xLVlFNY0ZxRlRkSUQzWnpOSnBwYlZLaTQ2Y2cva3AxVmR6SEp5YVdMTzNQQ2hQSUxESGJlSVh4VXdYYlBxNi9VZWsvYWZEQ0FjRFB4Mk4yNmo2cm5ZT242akFyczRCc1VYRDZxak05aUxWS2FhYldHRG5PRHlEZkw0VHg0ZElod1M0dnloNGZlaXRuVFQvcVRlSU56VWdCeXVtMkw2Zk5yUVFhOGd2M2JnUm9ZOFZZdmEvc29NakNZWDdmUit6MUFpY3lCOEJYZHpVSnczL3ZSSk5BSSs5NHJvWnJPVENNc2E2VnMvcGxGY1hMenQxTzVaVzJQOHNtMXRnQjNIaHQ0c1gvYUhkcjQ9

---
  apiVersion: storage.k8s.io/v1
  kind: StorageClass
  metadata:
    name: test-dynamic-sc
    namespace: test-csi
  provisioner: com.mapr.csi-nfskdf
  allowVolumeExpansion: true
  parameters:
      csiProvisionerSecretName: "mapr-ticket-secret"
      csiProvisionerSecretNamespace: "test-csi"
      csiNodePublishSecretName: "mapr-ticket-secret"
      csiNodePublishSecretNamespace: "test-csi"
      restServers: "20.6.0.59:8443"
      cldbHosts: "20.6.0.59:7222"
      cluster: "my.cluster.com"
      securityType: "secure" # Default: unsecure
      namePrefix: "csi-pv"
      mountPrefix: "/csi"
      advisoryquota: "100M"
  
  
  ---
  kind: PersistentVolumeClaim
  apiVersion: v1
  metadata:
    name: test-dynamic-pvc
    namespace: test-csi
  spec:
    storageClassName: test-dynamic-sc
    accessModes:
      - ReadWriteOnce
    resources:
      requests:
        storage: 5G
  
  ---
  apiVersion: v1
  kind: Pod
  metadata:
    name: test-dynamic-pod
    namespace: test-csi
  spec:
    containers:
    - name: busybox
      image: busybox
      args:
      - sleep
      - "1000000"
      resources:
        requests:
          memory: "2Gi"
          cpu: "500m"
      volumeMounts:
      - mountPath: /dynamic
        name: maprflex
    volumes:
      - name: maprflex
        persistentVolumeClaim:
          claimName: test-dynamic-pvc
```

```
apiVersion: v1
kind: Namespace
metadata:
  name: test-csi
  labels:
    name: test-csi

---
apiVersion: v1
kind: Secret
metadata:
  name: mapr-ticket-secret
  namespace: test-csi
type: Opaque
data:
  MAPR_CLUSTER_USER: bWFwcg==
  MAPR_CLUSTER_PASSWORD: bWFwcg==
  CONTAINER_TICKET: bXkuY2x1c3Rlci5jb20gTDBBS1hkWHNITlBFbG81QlM1R2NWY0xLVlFNY0ZxRlRkSUQzWnpOSnBwYlZLaTQ2Y2cva3AxVmR6SEp5YVdMTzNQQ2hQSUxESGJlSVh4VXdYYlBxNi9VZWsvYWZEQ0FjRFB4Mk4yNmo2cm5ZT242akFyczRCc1VYRDZxak05aUxWS2FhYldHRG5PRHlEZkw0VHg0ZElod1M0dnloNGZlaXRuVFQvcVRlSU56VWdCeXVtMkw2Zk5yUVFhOGd2M2JnUm9ZOFZZdmEvc29NakNZWDdmUit6MUFpY3lCOEJYZHpVSnczL3ZSSk5BSSs5NHJvWnJPVENNc2E2VnMvcGxGY1hMenQxTzVaVzJQOHNtMXRnQjNIaHQ0c1gvYUhkcjQ9

---
kind: StorageClass
apiVersion: storage.k8s.io/v1
metadata:
  name: manual
  namespace: test-csi
provisioner: kubernetes.io/no-provisioner
volumeBindingMode: WaitForFirstConsumer

---
kind: PersistentVolumeClaim
apiVersion: v1
metadata:
  name: test-static-pvc
  namespace: test-csi
spec:
  storageClassName: manual
  accessModes:
    - ReadWriteOnce
  resources:
    requests:
      storage: 5G

---
apiVersion: v1
kind: PersistentVolume
metadata:
  name: test-static-pv
  namespace: test-csi
spec:
  storageClassName: manual
  accessModes:
  - ReadWriteOnce
  persistentVolumeReclaimPolicy: Delete
  capacity:
    storage: 5Gi
  csi:
    nodePublishSecretRef:
      name: "mapr-ticket-secret"
      namespace: "test-csi"
    driver: com.mapr.csi-nfskdf
    volumeHandle: test-id
    volumeAttributes:
      volumePath: "/" # Default: "/"
      cluster: my.cluster.com
      cldbHosts: 20.6.0.59:7222
      securityType: "secure" # Default: Unsecure

---
apiVersion: v1
kind: Pod
metadata:
  name: test-static-pod
  namespace: test-csi
spec:
  containers:
  - name: busybox
    image: busybox
    args:
    - sleep
    - "1000000"
    resources:
      requests:
        memory: "2Gi"
        cpu: "500m"
    volumeMounts:
    - mountPath: /mapr
      name: maprflex
  volumes:
    - name: maprflex
      persistentVolumeClaim:
        claimName: test-static-pvc
```
