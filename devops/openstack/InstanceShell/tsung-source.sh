#!/bin/bash
yum update
yum install -y epel-release
yum install -y erlang perl* rrdtool-perl gnuplot ncurses-devel
wget http://tsung.erlang-projects.org/dist/tsung-1.6.0.tar.gz
tar -xvzf tsung-1.6.0.tar.gz
mv tsung-1.6.0 /opt/
cd /opt/tsung-1.6.0/
./configure --prefix=/usr/local/tsung --with-erlang=/usr/local/erlang
make
make install


#產生Web UI 測試報告
/usr/local/tsung/lib/tsung/bin/tsung_stats.pl
