* 安裝所需套件

```
yum install -y  bridge-utils\
                libvirt-python \
                libvirt-client \
                virt-install \
                virt-viewer \
                virt-manager libvirt \
                qemu-kvm qemu-img 
```

* vim /etc/sysconfig/selinux

```
SELinux=disabled
```

* 重新開機

```
reboot
```

* 啟動KVM

```
lsmod | grep kvm 
systemctl start libvirtd 
systemctl enable libvirtd
```



