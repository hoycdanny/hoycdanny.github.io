yum install -y yum-utils device-mapper-persistent-data lvm2

yum-config-manager --add-repo [https://download.docker.com/linux/centos/docker-ce.repo](https://download.docker.com/linux/centos/docker-ce.repo)

yum install -y docker-ce docker-ce-cli containerd.io

tar xzf cloudera-quickstart-vm-\*-docker.tar.gz

docker import - cloudera/quickstart:latest &lt; cloudera-quickstart-vm-\*-docker/\*.tar

docker run --hostname=quickstart.cloudera --privileged=true -tdi -p 8888:8888 -p 7180:7180 -p 7187:7187 -p 7189:7189 -p 80:80 -p 50070:50070 --device=/dev/sdb:/dev/sdb --device=/dev/sdc:/dev/sdc --device=/dev/sdd:/dev/sdd --device=/dev/sde:/dev/sde --device=/dev/sdf:/dev/sdf --device=/dev/sdg:/dev/sdg cloudera/quickstart:latest /usr/bin/docker-quickstart



cd /var/lib/hadoop-hdfs/cache/

mkdir disk1/ disk2/ disk3/ disk4/  disk5/ disk6

chmod 755 disk1/ disk2/ disk3/ disk4/  disk5/ disk6

chown -R hdfs:hadoop disk1/ disk2/ disk3/ disk4/  disk5/ disk6



mount /dev/sdb1 /var/lib/hadoop-hdfs/cache/disk1

mount /dev/sdc1 /var/lib/hadoop-hdfs/cache/disk2

mount /dev/sdd1 /var/lib/hadoop-hdfs/cache/disk3

mount /dev/sde1 /var/lib/hadoop-hdfs/cache/disk4

mount /dev/sdf1 /var/lib/hadoop-hdfs/cache/disk5

mount /dev/sdg1 /var/lib/hadoop-hdfs/cache/disk6



chown -R hdfs:hadoop data







fdisk /dev/sde

