#!/bin/bash
sed -i 's/127.0.0.1/test.mosquitto.org/g' \
        /tsung-1.6.0/examples/mqtt.xml \
        /tsung-1.6.0/examples/mqtt.xml
sed -i 's/5672/1883/g' \
        /tsung-1.6.0/examples/mqtt.xml \
        /tsung-1.6.0/examples/mqtt.xml
sed -i 's/5/1/g' \
        /tsung-1.6.0/examples/mqtt.xml \
        /tsung-1.6.0/examples/mqtt.xml
#tsung -f mqtt.xml start
