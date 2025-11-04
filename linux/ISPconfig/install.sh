#! /bin/bash
yum install epel-release nginx
cd /tmp;
yum install wget unzip net-tools epel-release nginx

wget http://prdownloads.sourceforge.net/courier/courier-authlib-0.60.2.tar.bz2
wget http://prdownloads.sourceforge.net/courier/courier-imap-4.2.1.tar.bz2
wget http://prdownloads.sourceforge.net/courier/maildrop-2.0.4.tar.bz2

sudo rpmbuild -ta courier-authlib-0.60.2.tar.bz2

wget --no-check-certificate -O installer.tgz "https://github.com/servisys/ispconfig_setup/tarball/master";
tar zxvf installer.tgz;
cd *ispconfig*;
bash install.sh
