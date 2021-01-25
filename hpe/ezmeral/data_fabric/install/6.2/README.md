# HPE Data Fabric 6.2 基本安裝
## 安裝Installer

### 調整Syscrtl 配置
```shell=
vim /etc/sysctl.conf
```
家入下面兩個選項
```shell=
vm.swappiness=1
```
*[參考連結](https://docs.datafabric.hpe.com/62/AdvancedInstallation/PreparingEachNode-memory.html?hl=swappiness)*
```shell=
net.ipv4.tcp_retries2=5
```
*[參考連結](https://docs.datafabric.hpe.com/62/AdvancedInstallation/PreparingEachNode-infrastructure.html?hl=ipv4.tcp_retries2)*
```shell=
重新啟動服務
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
```shell=
[root@df-node1 ~]# wget https://package.mapr.com/releases/installer/mapr-setup.sh -P /tmp
--2021-01-25 13:50:04--  https://package.mapr.com/releases/installer/mapr-setup.sh
Resolving package.mapr.com (package.mapr.com)... 13.35.34.92, 13.35.34.88, 13.35.34.67, ...
Connecting to package.mapr.com (package.mapr.com)|13.35.34.92|:443... connected.
HTTP request sent, awaiting response... 200 OK
Length: 138961 (136K) [text/x-sh]
Saving to: '/tmp/mapr-setup.sh'

mapr-setup.sh               100%[==========================================>] 135.70K  --.-KB/s    in 0.01s

2021-01-25 13:50:04 (9.57 MB/s) - '/tmp/mapr-setup.sh' saved [138961/138961]

[root@df-node1 ~]# bash /tmp/mapr-setup.sh

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

Enter [host:]port that cluster nodes connect to this host on [df-node1.hpe-taiwan-cic.net:9443]:

Testing for cluster admin account...

Enter MapR cluster admin name [mapr]:

User 'mapr' does not exist. Creating new cluster admin account...

Enter 'mapr' uid [5000]:
Enter 'mapr' group name [mapr]:
Enter 'mapr' gid [5000]:
Enter 'mapr' password:
Confirm 'mapr' password:
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
