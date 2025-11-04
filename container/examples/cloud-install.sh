#!/bin/sh
sudo apt-get update
sudo apt-get install linux-image-extra-`uname -r`
sudo apt-get install curl
curl -sSL https://get.docker.com | sudo sh
