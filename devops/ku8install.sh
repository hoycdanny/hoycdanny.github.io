#!/bin/bash
yum install update
sed -i 's/enforcing/disabled/g' /etc/selinux/config /etc/selinux/config
yum -y install \
        docker docker-registry



tar -vxf Prod_ku8_install.tar
cp ku8_install/docker-file/binfile/* /usr/bin/
cp ku8_install/docker-file/docker.service /usr/lib/systemd/system/
systemctl daemon-reload
systemctl enable docker
systemctl start docker

docker load -i ku8_install/ldap_install/openldap.tar.gz
mkdir /data/ldap/database
mkdir /data/ldap/config
sed -i 's/10.68.156.11:5000/10.0.0.11:5000/g' \
        ku8_install/docker-file/docker-config \
        /etc/sysconfig/docker-config
cd ku8_install/ldap_install
sh run_ldap.sh


docker cp newusers.hpe.ldif  $(docker ps | grep ldap | awk -F ' ' ' { print $1 }'):/
docker exec -ti $(docker ps | grep ldap | awk -F ' ' ' { print $1 }') sh
ldapadd -x -D "cn=admin,dc=fet,dc=com" -w admin -f /newusers.hpe.ldif
ldapsearch -x -b dc=fet,dc=com -D "cn=admin,dc=fet,dc=com" -w admin
exit

cp -R ku8_install/harbor_install/docker-compose /usr/bin/
sed -i 's/10.68.156.11/10.0.0.11/g' \
        ku8_install/harbor_install/harbor/harbor.cfg \
        ku8_install/harbor_install/harbor/harbor.cfg
sed -i 's/10.68.156.10:1389/10.0.0.11:1389 /g' \
        ku8_install/harbor_install/harbor/harbor.cfg \
        ku8_install/harbor_install/harbor/harbor.cfg
./ku8_install/harbor_install/harbor/prepare
./ku8_install/harbor_install/harbor/install.sh

add this to
ADD_REGISTRY='--add-registry 192.168.99.101:5000'
INSECURE_REGISTRY='--insecure-registry 192.168.99.101:5000'
service docker restart
docker login 10.0.2.111:5000

docker load -i./ku8_install/ku8manager/mysql5.7.18.tar.gz
docker load -i./ku8_install/ku8manager/ku8manager.tar.gz
sed -i 's/10.68.156.10/10.0.2.111/g' \
        ku8_install/ku8manager/conf/application.properties \
        ku8_install/ku8manager/conf/application.properties
cp ku8_install/ku8manager/init_multi_addon_harbor.sql /data/ku8manager/init_multi_addon_harbor.sql/
