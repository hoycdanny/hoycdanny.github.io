sudo useradd -m hadoop -s /bin/bash

sudo passwd hadoop

sudo adduser hadoop sudo

su hadoop



sudo apt-get update

sudo apt-get -y install default-jdk default-jre







vim ~/.bashrc

```bash
export JAVA_HOME=/usr/lib/jvm/java-8-openjdk-amd64
export PATH=$PATH:$JAVA_HOME/bin
export HADOOP_HOME=/usr/local/hadoop
export PATH=$PATH:$HADOOP_HOME/sbin:$HADOOP_HOME/bin
```







source ~/.bashrc







wget http://apache.mirror.gtcomm.net/hadoop/common/hadoop-3.2.0/hadoop-3.2.0.tar.gz

sudo tar -zxf ~/hadoop-3.2.0.tar.gz

cd /usr/local

sudo mv ~/hadoop-3.2.0/ ./hadoop

sudo chown -R hadoop /usr/local/hadoop







vim /etc/hosts

```bash
20.6.0.140      hadoop-namenode
20.6.0.141      hadoop-1
20.6.0.142      hadoop-2
20.6.0.143      hadoop-3
```







namenode

cd /usr/local/hadoop

vim ./etc/hadoop/namenode

```
namenode
```

vim ./etc/hadoop/core-site.xml

```xml
<configuration>
    <property>
        <name>hadoop.tmp.dir</name>
        <value>file:///usr/local/hadoop/tmp</value>
        <description>Abase for other temporary directories.</description>
    </property>
    <property>
        <name>fs.defaultFS</name>
        <value>hdfs://namenode:9000</value>
    </property>
</configuration>
```

vim ./etc/hadoop/hdfs-site.xml

```xml
<configuration>
    <property>
        <name>dfs.replication</name>
        <value>3</value>
    </property>
    <property>
        <name>dfs.namenode.name.dir</name>
        <value> file:/usr/local/hadoop/hadoopdata/hdfs/namenode</value>
    </property>
    <property>
        <name>dfs.datanode.data.dir</name>
        <value> file:/usr/local/hadoop/hadoopdata/hdfs/datanode</value>
    </property>
    <property>
        <name>dfs.permissions</name>
        <value>false</value>
    </property>
</configuration>
```

vim ./etc/hadoop/mapred-site.xml

```xml
<configuration>
   <property>
      <name>mapred.job.tracker</name>
      <value>namenode:54311</value>
   </property>
</configuration>
```

vim ./etc/hadoop/yarn-site.xml

```xml
<configuration>
    <property>
        <name>yarn.nodemanager.aux-services</name>
        <value>mapreduce_shuffle</value>
    </property>
    <property>
        <name>yarn.nodemanager.aux-services.mapreduce.shuffle.class</name>
        <value>org.apache.hadoop.mapred.ShuffleHandler</value>
    </property>
    <property>
        <name>yarn.resourcemanager.resource-tracker.address</name>
        <value>namenode:8025</value>
    </property>
    <property>
        <name>yarn.resourcemanager.scheduler.address</name>
        <value>namenode:8030</value>
    </property>
    <property>
        <name>yarn.resourcemanager.address</name>
        <value>namenode:8050</value>
    </property>
    <property>
        <name>yarn.nodemanager.resource.cpu-vcores</name>
        <value>8</value>
    </property>
    <property>
        <name>yarn.nodemanager.resource.memory-mb</name>
        <value>8192</value>
    </property>
 </configuration>
```













datanode

vim ./etc/hadoop/core-site.xml

```xml
<configuration>
<property>
    <name>hadoop.tmp.dir</name>
    <value>file:///usr/local/hadoop/tmp</value>
    <description>Abase for other temporary directories.</description>
</property>
<property>
    <name>fs.defaultFS</name>
    <value>hdfs://namenode:9000</value>
</property>
</configuration>
```

vim ./etc/hadoop/hdfs-site.xml

```xml
<configuration>
<property>
   <name>dfs.replication</name>
   <value>3</value>
</property>
<property>
   <name>dfs.datanode.data.dir</name>
   <value> file:/usr/local/hadoop/hadoop_data/hdfs/datanode</value>
</property> 
</configuration>
```

vim ./etc/hadoop/mapred-site.xml

```xml
<configuration>
<property>
   <name>mapred.job.tracker</name>
   <value>namenode:54311</value>
</property>
</configuration>
```

vim ./etc/hadoop/yarn-site.xml

```xml
<configuration>
<property>
     <name>yarn.resourcemanager.resource-tracker.address</name>
     <value>namenode:8025</value>
 </property>
<property>
     <name>yarn.resourcemanager.scheduler.address</name>
     <value>namenode:8030</value>
 </property>
<property>
     <name>yarn.resourcemanager.address</name>
     <value>namenode:8050</value>
 </property> 
 </configuration>
```





scp -rp hadoop hadoop@20.6.0.141:/usr/local

ssh-keygen

ssh-copy-id 



datanode

```
sudo rm -rf /usr/local/hadoop/hadoop_data/hdfs
sudo mkdir -p /usr/local/hadoop/hadoop_data/hdfs/datanode
sudo chown hadoop:hadoop -R /usr/local/hadoop
```

namenode

```
sudo rm -rf /usr/local/hadoop/hadoop_data/hdfs
sudo mkdir -p /usr/local/hadoop/hadoop_data/hdfs/namenode
sudo chown hadoop:hadoop -R /usr/local/hadoop
```

namenode

```
hadoop namenode -format
```

datanode

```
hadoop datanode-format
```



vim /usr/local/hadoop/etc/hadoop/hadoop-env.sh

```
export JAVA_HOME=/usr/lib/jvm/java-8-openjdk-amd64
```









./hadoop/sbin/start-dfs.sh



