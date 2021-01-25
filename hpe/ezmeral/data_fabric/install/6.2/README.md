# HPE Data Fabric 6.2 基本安裝
## 環境描述
### Apollo 4530 (ProLiant XL450 Gen9 Server *3)

* OS Red Hat Enterprise Linux release 8.2 (Ootpa)
* 15 * MB6000JVYZD
* 

## 環境配置
### 檢查CPU與作業系統
```shell=
uname -m
```
`x86_64`

 *i386, i486, i586, i686 這些都不支援MapR*
 
### 檢查作業系統版本
```shell=
cat /etc/redhat-release
```
`Red Hat Enterprise Linux release 8.2 (Ootpa)`

[作業系統支援列表](https://docs.datafabric.hpe.com/62/InteropMatrix/r_os_matrix_6.x.html)

### 網路配置檢查
```shell=
hostname -f
```
`df-node1.hpe-taiwan-cic.net`

檢查每個節點是否可透過FQDN溝通

```shell=
getent hosts 'df-node1.hpe-taiwan-cic.net'
getent hosts 'df-node2.hpe-taiwan-cic.net'
getent hosts 'df-node3.hpe-taiwan-cic.net'
```

`20.6.0.121 df-node1.hpe-taiwan-cic.net`
`20.6.0.122 df-node1.hpe-taiwan-cic.net`
`20.6.0.123 df-node1.hpe-taiwan-cic.net`

## 安裝Installer

### 調整Syscrtl 配置
```shell=
vim /etc/sysctl.conf
```
在sysctl.conf中加入下面兩個選項

`vm.swappiness=1`

`net.ipv4.tcp_retries2=5`

*[swappiness, ](https://docs.datafabric.hpe.com/62/AdvancedInstallation/PreparingEachNode-memory.html?hl=swappiness)*
*[tcp_retries2](https://docs.datafabric.hpe.com/62/AdvancedInstallation/PreparingEachNode-infrastructure.html?hl=ipv4.tcp_retries2)*

重新啟動服務

```shell=
sysctl -p
```
### Start chronyd service
```shell=
systemctl start chronyd
```
### Disable & Stop SELINUX service
```shell=
setenforce 0
sed -i --follow-symlinks 's/SELINUX=enforcing/SELINUX=disabled/g' /etc/sysconfig/selinux
```
### 下載MapR Installer
```shell=
wget https://package.mapr.com/releases/installer/mapr-setup.sh -P /tmp
```

### 開始安裝MapR Installer

```shell=
bash /tmp/mapr-setup.sh
```
看到`Install required packages?`記得輸入`y`並按下`[Enter]`

```shell=
                        HPE Ezmeral Data Fabric Distribution Initialization and Update

                Copyright 2021 Hewlett Packard Enterprise Development LP., All Rights Reserved
                              https://www.hpe.com/us/en/software/data-fabric.html
Install required packages? (y/n) [y]: y
Failed to set locale, defaulting to C.UTF-8
warning: /var/cache/dnf/rhel-8-for-x86_64-baseos-rpms-51b3b78d5698246b/packages/python3-setuptools-39.2.0-5.el8.noarch.rpm: Header V3 RSA/SHA256 Signature, key ID fd431d51: NOKEY
Importing GPG key 0xFD431D51:
 Userid     : "Red Hat, Inc. (release key 2) <security@redhat.com>"
 Fingerprint: 567E 347A D004 4ADE 55BA 8A5F 199E 2F91 FD43 1D51
 From       : /etc/pki/rpm-gpg/RPM-GPG-KEY-redhat-release
Importing GPG key 0xD4082792:
 Userid     : "Red Hat, Inc. (auxiliary key) <security@redhat.com>"
 Fingerprint: 6A6A A7C9 7C88 90AE C6AE BFE2 F76F 66C3 D408 2792
 From       : /etc/pki/rpm-gpg/RPM-GPG-KEY-redhat-release

Installing installer package dependencies...

Failed to set locale, defaulting to C.UTF-8
Failed to set locale, defaulting to C.UTF-8
Error: Unable to find a match: epel-release
Failed to set locale, defaulting to C.UTF-8
Failed to set locale, defaulting to C.UTF-8
Failed to set locale, defaulting to C.UTF-8
warning: /var/cache/dnf/epel-fafd94c310c51e1e/packages/sshpass-1.06-9.el8.x86_64.rpm: Header V3 RSA/SHA256 Signature, key ID 2f86d6a1: NOKEY
Importing GPG key 0x2F86D6A1:
 Userid     : "Fedora EPEL (8) <epel@fedoraproject.org>"
 Fingerprint: 94E2 79EB 8D8F 25B2 1810 ADF1 21EA 45AB 2F86 D6A1
 From       : /etc/pki/rpm-gpg/RPM-GPG-KEY-EPEL-8

...Success

Testing for java-11-openjdk-devel or higher...

JDK not found - installing java-11-openjdk-devel...

Failed to set locale, defaulting to C.UTF-8
...Success

Testing connection to http://package.mapr.com/releases/installer...

...Success
```

這邊需要輸入相關訊息包含uid, gid, password

```shell=
Enter [host:]port that cluster nodes connect to this host on [df-node1.hpe-taiwan-cic.net:9443]:

Testing for cluster admin account...

Enter MapR cluster admin name [mapr]: [MapR Admin 預設是mapr] 按[Enter] 下一步

User 'mapr' does not exist. Creating new cluster admin account...

Enter 'mapr' uid [5000]:          [預設uid是5000] 按[Enter] 下一步
Enter 'mapr' group name [mapr]:   [預設group name是mapr] 按[Enter] 下一步
Enter 'mapr' gid [5000]:          [預設gid是5000] 按[Enter] 下一步
Enter 'mapr' password:            [輸入mapr的密碼] 按[Enter] 下 一步
Confirm 'mapr' password:          [再次輸入mapr的密碼] 按[Enter] 下一步
...Success


Installing installer packages...

Failed to set locale, defaulting to C.UTF-8
Updating Subscription Management repositories.
35 files removed
Failed to set locale, defaulting to C.UTF-8

...Success

       To continue installing HPE Ezmeral Data Fabric software, open the following URL in a web browser

                       If the address 'df-node1.hpe-taiwan-cic.net' is internal and not
                  accessible from your browser, use the external address mapped to it instead

                                   https://df-node1.hpe-taiwan-cic.net:9443
```


#### 輸入IP開始安裝https://IP-Address:9443
![](https://i.imgur.com/SQBtQVN.png)
![](https://i.imgur.com/OqHAuFb.png)

---

####註冊MapR User [連結](https://mapr.com/user/)
![](https://i.imgur.com/oGTem4v.png)

---

![](https://i.imgur.com/MdmBdiV.png)
![](https://i.imgur.com/x3NsMBn.png)
![](https://i.imgur.com/38iCfKm.png)
![](https://i.imgur.com/FaUB5GM.png)
![](https://i.imgur.com/XI8kobJ.png)
![](https://i.imgur.com/ae672bv.png)

#### 輸入Node hostname
![](https://i.imgur.com/4Viml90.png)

#### 輸入帳號與密碼 這邊使用`root` 透過`ssh`
![](https://i.imgur.com/Byisssi.png)

---

#### 驗證完畢
![](https://i.imgur.com/8gGLOhr.png)

---

*Note 記得選硬碟！*
#### 如下圖
![](https://i.imgur.com/VcMVSJD.png)

---

#### 確認Layout
#### 可參考[這邊](https://docs.datafabric.hpe.com/62/AdvancedInstallation/PlanningtheCluster-examples.html)規劃

![](https://i.imgur.com/ZxNYu3L.png)


---

#### 開始安裝
![](https://i.imgur.com/idiw3sI.png)

---

#### 安裝完成
![](https://i.imgur.com/s3aJksf.png)
![](https://i.imgur.com/Ye3ofZ0.png)

#### 輸入IP使用MapR https://<ip>:8443
![](https://i.imgur.com/4LUU0YH.png)

![](https://i.imgur.com/jsEzIa0.png)

