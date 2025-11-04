#!/bin/bash
#use ubuntu 16.04
sudo apt-get update
sudo apt-get install docker.io -y


sed -e '1 a/ $(whoami)' /etc/hosts
http://openstack.danny-zone.com/dashboard


#!/bin/bash
yum -y update
yum -y install docker docker-registry
systemctl enable docker
systemctl start docker
sed -e '1 a/ $(whoami)' /etc/hosts
