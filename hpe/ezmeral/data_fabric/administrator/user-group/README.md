# Administering Users and Groups

## 用戶說明

* `root` 用於在每個節點上 HPE Data Fabric `安裝`。
* `mapr` 是在每個節點上 HPE Data Fabric `運行服務` 與 `管理權限` 的用戶。

## 帳戶管理

```shell=
groupadd hpe-taiwan-cic --gid 1234
useradd danny --uid 5678 --gid 1234
```

> 如果有多個節點，請記得在每個node上都新增User and Group 

> 如果要部署大型Cluster，則應考慮將所有節點配置為使用LDAP或其他用戶管理系統。


## 設定 `SMTP` 提醒

```shell=
maprcli config save -values '{"mapr.smtp.provider":"gmail",
               "mapr.smtp.server":"smtp.gmail.com",
               "mapr.smtp.sslrequired":"true",
               "mapr.smtp.port":"465",
               "mapr.smtp.sender.fullname":"Ab  Cd",
               "mapr.smtp.sender.email":"xxx@gmail.com",
               "mapr.smtp.sender.username":"xxx@gmail.com",
               "mapr.smtp.sender.password":"abc"}'
```

https://docs.datafabric.hpe.com/61/AdministratorGuide/t_setting_up_SMTP.html


## 利用CLI賦予 ACL 權限

> 使用用戶 `mapr`

### 設置ACL
```shell=
maprcli acl set
    [ -cluster <cluster name> ]
    [ -group <group> ]
    [ -name <name> ]
    -type cluster|volume
    [ -user <user> ]
```

### 編輯ACL

```shell=
maprcli acl edit -type cluster -user <user>:fc
```

### 黑名單使用者

```shell=
maprcli blacklistuser -user <user name> 
```

https://docs.datafabric.hpe.com/61/AdministratorGuide/SettingUserPermissions-AddingClusterPermissions.html


## 設定LDAP整合

### 使用 Docker 模擬LDAP Server
```shell=
setenforce 0
sed -i --follow-symlinks 's/SELINUX=enforcing/SELINUX=disabled/g' /etc/sysconfig/selinux
systemctl stop firewalld
systemctl disable firewalld

yum install -y yum-utils
yum-config-manager \
    --add-repo \
    https://download.docker.com/linux/centos/docker-ce.repo
yum install docker-ce docker-ce-cli containerd.io
systemctl enable docker
systemctl start docker

docker run -d \
    -p 389:389 -p 636:636 \
    --env LDAP_ORGANISATION="HPE Taiwan CIC LDAP" \
    --env LDAP_DOMAIN="hpe-taiwan-cic.net" \
    --env LDAP_ADMIN_PASSWORD="password" \
    --env LDAP_CONFIG_PASSWORD="password" \
    --env LDAP_READONLY_USER="true" \
    --env LDAP_READONLY_USER_USERNAME="testuser" \
    --env LDAP_READONLY_USER_PASSWORD="testuser" \
    --name openldap-server \
    osixia/openldap:1.4.0

docker run -d \
    -p 443:443 \
    --env PHPLDAPADMIN_LDAP_HOSTS=172.17.0.2 \
    --name phpldapadmin \
    osixia/phpldapadmin:0.7.1
```

#### 連入 [ Docker LDAP Server] 

```shell=
docker exec -ti openldap-server /bin/bash
```

#### [ Docker LDAP Server] ldap.conf

vim /etc/openldap/ldap.conf
```shell=
TLS_CACERTDIR /etc/openldap/cacerts
# Turning this off breaks GSSAPI used with krb5 when rdns = false
SASL_NOCANON    on
URI ldap://20.6.0.61/
BASE dc=hpe-taiwan-cic,dc=net
```

#### [Docker LDAP Server] Enable LADP Config 

```shell=
authconfig \
--enableldap \
--enableldapauth \
--ldapserver='ldap://20.6.0.61/' \
--ldapbasedn='dc=hpe-taiwan-cic,dc=net' \
--enablemkhomedir \
--enableshadow \
--enablelocauthorize \
--passalgo=sha256 \
--update
```

#### [Docker LDAP Server] Edit nslcd.conf 

```shell=
vim /etc/nslcd.conf
====================================================
uri ldap://20.6.0.61/
base dc=hpe-taiwan-cic,dc=net
binddn cn=admin,dc=hpe-taiwan-cic,dc=net
bindpw password
====================================================
systemctl restart nslcd
```

## 在 `HPE Data Fabric` 每個節點執行下面這些步驟

### 安裝 `LDAP Client` 與 `PAM LDAP`

```shell=
yum install –y openldap-clients pam_ldap
```

### [PAM]mapr-admin

#### 配置 `mapr-admin` /etc/pam.d/mapr-admin

```shell=
account     required      pam_unix.so
account     sufficient    pam_succeed_if.so uid < 1000 quiet
account     [default=bad success=ok user_unknown=ignore] pam_ldap.so
account     required      pam_permit.so
 
auth        sufficient      pam_unix.so nullok_secure
auth        requisite       pam_succeed_if.so uid >= 1000 quiet
auth        sufficient      pam_ldap.so use_first_pass
auth        required        pam_deny.so
 
password    sufficient    pam_unix.so md5 obscure min=4 max=8 nullok
try_first_pass
password    sufficient    pam_ldap.so
password    required      pam_deny.so
 
session     required      pam_limits.so
session     required      pam_unix.so
session     optional      pam_ldap.so
```

### 配置 `nslcd Service` 

#### `nsswitch.conf` 檔案 /etc/nsswitch.conf

```shell=
#
# /etc/nsswitch.conf
#
# An example Name Service Switch config file. This file should be
# sorted with the most-used services at the beginning.
#
# The entry '[NOTFOUND=return]' means that the search for an
# entry should stop if the search in the previous entry turned
# up nothing. Note that if the search failed due to some other reason
# (like no NIS server responding) then the search continues with the
# next entry.
#
# Valid entries include:
#
#	nisplus			Use NIS+ (NIS version 3)
#	nis			Use NIS (NIS version 2), also called YP
#	dns			Use DNS (Domain Name Service)
#	files			Use the local files
#	db			Use the local database (.db) files
#	compat			Use NIS on compat mode
#	hesiod			Use Hesiod for user lookups
#	[NOTFOUND=return]	Stop searching if not found so far
#

# To use db, put the "db" in front of "files" for entries you want to be
# looked up first in the databases
#
# Example:
#passwd:    db files nisplus nis
#shadow:    db files nisplus nis
#group:     db files nisplus nis

passwd:     files sss ldap
shadow:     files sss ldap
group:      files sss ldap
#initgroups: files sss

#hosts:     db files nisplus nis dns
hosts:      files dns myhostname

# Example - obey only what nisplus tells us...
#services:   nisplus [NOTFOUND=return] files
#networks:   nisplus [NOTFOUND=return] files
#protocols:  nisplus [NOTFOUND=return] files
#rpc:        nisplus [NOTFOUND=return] files
#ethers:     nisplus [NOTFOUND=return] files
#netmasks:   nisplus [NOTFOUND=return] files

bootparams: nisplus [NOTFOUND=return] files

ethers:     files
netmasks:   files
networks:   files
protocols:  files
rpc:        files
services:   files sss

netgroup:   files sss ldap

publickey:  nisplus

automount:  files ldap
aliases:    files nisplus
```


#### 啟動 nslcd

```shell=
systemctl start nslcd
```

#### Debug Mode nslcd

```shell=
systemctl restart nslcd
systemctl stop nslcd
nslcd -d (debug mode)
```

### 配置 `MCS` 

#### mapr.login.conf

vim /opt/mapr/conf/mapr.login.conf

```shell=
jpamLogin {
/**
 * net.sf.jpam.jaas.JpamLoginModule Sufficient
 *     serviceName="sudo"
 *     debug=true;
 * net.sf.jpam.jaas.JpamLoginModule Sufficient
 *     serviceName="sshd"
 *     debug=true;
 */
  net.sf.jpam.jaas.JpamLoginModule Sufficient
      serviceName="mapr-admin"
      debug=true;
};
```

#### properties.cfg

vim /opt/mapr/apiserver/conf/properties.cfg

```shell=
ojai.cache.size=64
mapr.webui.https.port=8443
doc.url=https://mapr.com/docs/
proxy.zkservices=elasticsearch,opentsdb
activity.metrics.thread.pool.size=10
authentication.pam.service=mapr-admin
```

#### Restart apiserver service

```shell=
maprcli node list
maprcli node services -action restart -name apiserver -nodes 'df.hpe-taiwan-cic.net'
```
