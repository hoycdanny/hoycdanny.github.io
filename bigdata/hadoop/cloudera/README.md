yum install -y yum-utils device-mapper-persistent-data lvm2

yum-config-manager --add-repo https://download.docker.com/linux/centos/docker-ce.repo

yum install -y docker-ce docker-ce-cli containerd.io



tar xzf cloudera-quickstart-vm-\*-docker.tar.gz

docker import - cloudera/quickstart:latest &lt; cloudera-quickstart-vm-\*-docker/\*.tar

docker run --hostname=quickstart.cloudera --privileged=true -tdi -p 8888:8888 -p 7180:7180 -p 80:80 --device=/dev/sdb:/dev/sdb --device=/dev/sdc:/dev/sdc --device=/dev/sdd:/dev/sdd --device=/dev/sde:/dev/sde --device=/dev/sdf:/dev/sdf --device=/dev/sdg:/dev/sdg cloudera/quickstart:lates /usr/bin/docker-quickstart 







chown -R hdfs:hadoop data

