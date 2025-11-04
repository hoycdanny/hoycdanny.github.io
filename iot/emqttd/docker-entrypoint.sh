#!/bin/bash
sed -i 's/emqttd@127.0.0.1/'$HOSTNAME'/g' \
        /emqttd/etc/emq.conf \
        /emqttd/etc/emq.conf
./emqttd/bin/emqttd start 
