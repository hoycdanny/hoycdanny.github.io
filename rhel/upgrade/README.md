# RHEL 升級 7.9 to 8.2

```shell=
[root@datafabric ~]# subscription-manager list --installed
+-------------------------------------------+
    已安裝之產品的狀態
+-------------------------------------------+
產品名稱：       Red Hat Enterprise Linux Server
產品 ID：        69
版本：           7.9
架構：           x86_64
狀態：           已訂閱
狀態的詳細資料：
起始：           西元2018年09月01日
結束：           西元2025年04月01日

[root@datafabric ~]# subscription-manager repos --enable rhel-7-server-rpms
軟體庫 'rhel-7-server-rpms' 已啟用於這部系統。

[root@datafabric ~]# subscription-manager repos --enable rhel-7-server-extras-rpms
軟體庫 'rhel-7-server-extras-rpms' 已啟用於這部系統。

[root@datafabric ~]# subscription-manager release --unset
發行版偏好設定設置已取消

[root@datafabric ~]# yum update
[root@datafabric ~]# reboot
[root@datafabric ~]# yum install leapp leapp-repository
```
```shell=
Download https://access.redhat.com/articles/3664871
[root@datafabric ~]# mv leapp-data12.tar.gz /etc/leapp/files/leapp-data12.tar.gz
[root@datafabric ~]# cd /etc/leapp/files/
[root@datafabric files]# tar -xzf leapp-data12.tar.gz -C /etc/leapp/files && rm leapp-data12.tar.gz
```
```shell=
vim /etc/ssh/sshd_config.
找到 #PermitRootLogin yes.
移除 (#) 
儲存檔案
```
### 執行Preupgrade
```shell=
[root@datafabric ~]# leapp answer --section remove_pam_pkcs11_module_check.confirm=True
[root@datafabric files]# leapp preupgrade
```
![](https://i.imgur.com/hsBU7R7.png)
### 執行Upgrade
```shell=
[root@datafabric ~]# leapp upgrade
[root@datafabric ~]# reboot
```
### 驗證升級完成
```shell=
[root@datafabric ~]# cat /etc/os-release
NAME="Red Hat Enterprise Linux"
VERSION="8.2 (Ootpa)"
ID="rhel"
ID_LIKE="fedora"
VERSION_ID="8.2"
PLATFORM_ID="platform:el8"
PRETTY_NAME="Red Hat Enterprise Linux 8.2 (Ootpa)"
ANSI_COLOR="0;31"
CPE_NAME="cpe:/o:redhat:enterprise_linux:8.2:GA"
HOME_URL="https://www.redhat.com/"
BUG_REPORT_URL="https://bugzilla.redhat.com/"

REDHAT_BUGZILLA_PRODUCT="Red Hat Enterprise Linux 8"
REDHAT_BUGZILLA_PRODUCT_VERSION=8.2
REDHAT_SUPPORT_PRODUCT="Red Hat Enterprise Linux"
REDHAT_SUPPORT_PRODUCT_VERSION="8.2"
```


