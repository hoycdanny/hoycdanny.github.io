#!/bin/bash
yum install -y  -y
yum install -y centos-release-openshift-origin
yum install -y vim git httpd-tools bind-utils wget net-tools bind-utils iptables-services bridge-utils bash-completion origin-clients bind wget git net-tools bind-utils iptables-services bridge-utils bash-completion origin-clients
sed -i '/OPTIONS=.*/c\OPTIONS="--selinux-enabled --insecure-registry 172.30.0.0/16"' /etc/sysconfig/docker
systemctl is-active docker
systemctl enable docker
systemctl start docker
#oc cluster up --public-hostname=10.28.120.35




docker run -d --name "origin" \
  --privileged --pid=host --net=host \
  -v /:/rootfs:ro -v /var/run:/var/run:rw -v /sys:/sys -v /sys/fs/cgroup:/sys/fs/cgroup:rw \
  -v /var/lib/docker:/var/lib/docker:rw \
  -v /var/lib/origin/openshift.local.volumes:/var/lib/origin/openshift.local.volumes:rslave \
  openshift/origin start



  docker run -d --name "origin"   --privileged --pid=host --net=host   -v /:/rootfs:ro -v /var/run:/var/run:rw -v /sys:/sys -v /sys/fs/cgroup:/sys/fs/cgroup:rw   -v /var/lib/docker:/var/lib/docker:rw   -v /var/lib/origin/openshift.local.volumes:/var/lib/origin/openshift.local.volumes:rslave openshift/origin start
