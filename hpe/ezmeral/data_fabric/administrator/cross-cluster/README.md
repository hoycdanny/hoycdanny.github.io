
vim /etc/hosts

```shell=
20.6.0.121  datafabric01.hpe-taiwan-cic.net
20.6.0.122  datafabric02.hpe-taiwan-cic.net
20.6.0.123  datafabric03.hpe-taiwan-cic.net
20.6.0.125  edge-mapr.hpe-taiwan-cic.net
```

vim /opt/mapr/conf/mapr-clusters.conf

```shell
my.cluster.com secure=true datafabric01.hpe-taiwan-cic.net:7222 datafabric02.hpe-taiwan-cic.net:7222 datafabric03.hpe-taiwan-cic.net:7222
edge.cluster.com secure=true edge-mapr.hpe-taiwan-cic.net:7222
```



```shell=
yum -y install https://dl.fedoraproject.org/pub/epel/epel-release-latest-8.noarch.rpm
yum update
yum install pssh expect -y 
```

Join Cluster

```shell
[root@datafabric01 ~]# /opt/mapr/server/configure-crosscluster.sh create all -remoteip 20.6.0.125
Remote IP is 20.6.0.125
WARNING: Strict host key checking will be disabled for this script.
Local user unset, defaulting to mapr
Remote user unset, defaulting to local user mapr
Enter password for mapr user (mapr) for local cluster:
Enter password for mapr user (mapr) for remote cluster:
Local cross-cluster user unset, defaulting to local user mapr
Remote cross-cluster user unset, defaulting to remote user mapr
Verifying connectivity to 20.6.0.125 and presence of mapr-clusters.conf
MapR credentials of user 'mapr' for cluster 'my.cluster.com' are written to '/tmp/maprticket_0'
Local host is running the CLDB
my.cluster.com secure=true datafabric01.hpe-taiwan-cic.net:7222 datafabric02.hpe-taiwan-cic.net:7222 datafabric03.hpe-taiwan-cic.net:7222
Configuring cross-cluster communication for users
Certificate stored in file </tmp/mapr-xcs/3899186/local_mapcert>
Certificate stored in file </tmp/mapr-xcs/3899186/remote_mapcert>
Successfully exported certificate for remote cluster to /tmp/mapr-xcs/3899186/remote_mapcert
Certificate was added to keystore
Certificate was added to keystore
Configuring cross-cluster communication for server-side operations
Generating cross-cluster ticket for user mapr on remote node
Generating cross-cluster ticket for mirroring for user mapr
MapR credentials of user 'mapr' for cluster 'my.cluster.com' are written to '/tmp/mapr-xcs/3899186/local_crosscluster_ticket'
SUCCESS
This script has logged in to both the local and remote clusters. Please log out of
the clusters if needed.
```
