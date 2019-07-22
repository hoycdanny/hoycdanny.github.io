yum -y update

yum install -y  java-1.8.0-openjdk

adduser hadoop

passwd hadoop

su - hadoop

ssh-keygen -t rsa -P '' -f ~/.ssh/id\_rsa

cat ~/.ssh/id\_rsa.pub &gt;&gt; ~/.ssh/authorized\_keys

chmod 0600 ~/.ssh/authorized\_keys

cd ~

wget http://www-eu.apache.org/dist/hadoop/common/hadoop-3.2.0/hadoop-3.2.0.tar.gz

tar xzf hadoop-3.2.0.tar.gz

mv hadoop-3.2.0 hadoop



vim ~/.bashrc

export HADOOP\_HOME=/home/hadoop/hadoop

export HADOOP\_INSTALL=$HADOOP\_HOME

export HADOOP\_MAPRED\_HOME=$HADOOP\_HOME

export HADOOP\_COMMON\_HOME=$HADOOP\_HOME

export HADOOP\_HDFS\_HOME=$HADOOP\_HOME

export YARN\_HOME=$HADOOP\_HOME

export HADOOP\_COMMON\_LIB\_NATIVE\_DIR=$HADOOP\_HOME/lib/native

export PATH=$PATH:$HADOOP\_HOME/sbin:$HADOOP\_HOME/bin

source ./.bashrc



vim core-site.xml

vim hdfs-site.xml

vim mapred-site.xml 

vim yarn-site.xml



java -XshowSettings:properties -version 2&gt;&1 &gt; /dev/null \| grep 'java.home'

export JAVA\_HOME=/usr/lib/jvm/jre-1.8.0-openjdk

hdfs namenode -format





cd $HADOOP\_HOME/sbin/

./start-dfs.sh



























wget https://dl.google.com/go/go1.12.6.linux-amd64.tar.gz

tar -xzf go1.12.6.linux-amd64.tar.gz

mv go /usr/local

export GOROOT=/usr/local/go

export GOPATH=/usr/local/go/bin

export PATH=$GOPATH/bin:$GOROOT/bin:$PATH

go version

go env

git clone https://github.com/openshift/installer.git

cd installer/

hack/build.sh

