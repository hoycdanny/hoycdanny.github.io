#! /bin/bash
subnet="192.168.21.0"
netmask="255.255.255.0"
dhcpserver="192.168.21.11"
gateway="192.168.21.1"
ipstart="192.168.21.100"
ipend="192.168.21.200"
broadcastaddress="192.168.21.255"
dnsserver="8.8.8.8"
dhcpeth="eno1"

yum update
yum -y install httpd xinetd syslinux tftp-server dhcp
mount /dev/sr0 /mnt
mkdir /var/www/centos7
cp -a /mnt/* /var/www/centos7/
chmod -R 755 /var/www/centos7/


cat > /etc/httpd/conf.d/pxe.conf <<- "EOF"
	Alias /centos7 /var/www/centos7/
	<Directory /var/www/centos7/>
	Options Indexes FollowSymLinks
	Order Deny,Allow
	Allow from all
	</Directory>
EOF

cp -a /usr/share/syslinux/* /var/lib/tftpboot/
mkdir /var/lib/tftpboot/centos7
cp /var/www/centos7/images/pxeboot/vmlinuz  /var/lib/tftpboot/centos7
cp /var/www/centos7/images/pxeboot/initrd.img  /var/lib/tftpboot/centos7
mkdir /var/lib/tftpboot/pxelinux.cfg

cat > /var/lib/tftpboot/pxelinux.cfg/default <<- "EOF"
default menu.c32
prompt 0
timeout 300
ONTIMEOUT 1
menu title ########## CentOS 7 PXE Boot Menu ##########
label 1
menu label ^1) Install CentOS 7
menu default
kernel centos7/vmlinuz
append initrd=centos7/initrd.img method=http://"$dhcpserver"/centos7 devfs=nomount
label 2
menu label ^2) Boot from local drive
localboot 0
EOF


cat > /etc/xinetd.d/tftp <<- "EOF"
service tftp
{
        socket_type             = dgram
        protocol                = udp
        wait                    = yes
        user                    = root
        server                  = /usr/sbin/in.tftpd
        server_args             = -s /var/lib/tftpboot
        disable                 = no
        per_source              = 11
        cps                     = 100 2
        flags                   = IPv4
}
EOF

cat > /etc/dhcp/dhcpd.conf <<- "EOF"
default-lease-time 600;
max-lease-time 7200;
log-facility local7;
subnet "$subnet" netmask "$netmask" {
 range "$ipstart" "$ipend";
 option domain-name-servers "$dnsserver";
 option domain-name "itzgeek.local";
 option routers "$gateway";
 option broadcast-address "$broadcastaddress";
 default-lease-time 600;
 max-lease-time 7200;
 filename "pxelinux.0";
}
EOF

cp /usr/lib/systemd/system/dhcpd.service /etc/systemd/system/
sed -i '10s/$/"$dhcpeth"/' /etc/systemd/system/dhcpd.service
systemctl --system daemon-reload
systemctl restart xinetd
systemctl restart httpd
systemctl restart dhcpd
systemctl enable xinetd
systemctl enable httpd
systemctl enable dhcpd
firewall-cmd --permanent --add-service=http
firewall-cmd --permanent --add-service=dhcp
firewall-cmd --permanent --add-port=69/udp
firewall-cmd --permanent --add-port=69/tcp
firewall-cmd --reload


cat > /var/www/centos7/ks/ks.cfg <<- "EOF"
#platform=x86, AMD64, or Intel EM64T
#version=DEVEL
# Install OS instead of upgrade
install
# Keyboard layouts
keyboard 'us'
#Root Password
rootpw --iscrypted $1$YmE61tG8$0ifUyLjNqPUpvqarTYP4l1
# Use network installation
url --url="http://"$dhcpserver"/centos7"
# System language
lang en_US
# Firewall configuration
firewall --disabled
# System authorization information
auth  --useshadow  --passalgo=sha512
# Use graphical install
graphical
firstboot --disable
# SELinux configuration
selinux --enforcing

# Network information
network  --bootproto=dhcp --device=eth0
# Halt after installation
halt
# System timezone
timezone Asia/Taipei
# System bootloader configuration
bootloader --location=mbr
# Partition clearing information
clearpart --all
# Disk partitioning information
part / --fstype="ext4" --grow --size=102400
part swap --fstype="swap" --size=500
part /boot --fstype="ext4" --size=200
%packages
@^Infrastructure Server
%end
reboot
EOF

cat > /var/lib/tftpboot/pxelinux.cfg/default <<- "EOF"
default menu.c32
prompt 0
timeout 100
ONTIMEOUT 1
menu title ########## CentOS 7 PXE Boot Menu ##########
label 1
menu label ^1) Boot from local drive
menu default
LOCALBOOT 0
label 2
menu label ^2) Install KS  CentOS 7
kernel centos7/vmlinuz
append initrd=centos7/initrd.img ks=http://"$dhcpserver"/centos7/ks/ks.cfg
EOF
