#!/bin/bash
apt-get update
apt-get install -y wget erlang git make
wget http://emqtt.io/downloads/latest/ubuntu16_04-deb
dpkg -i ubuntu16_04-deb
git clone https://github.com/emqtt/emqtt_benchmark.git
cd emqtt_benchmark
make
emqttd start
