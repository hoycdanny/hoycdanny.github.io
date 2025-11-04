#!/bin/sh
service sshd start
echo ${MARATHON_URL} > /etc/tsung/marathon_url
crontab /etc/crontab
service crond start
slave=$(echo $SLAVE)
if [[ -n "${slave}" ]]; then
    echo "Running in SLAVE mode ..."
    tail -f /var/log/tsung/tsung-update-hosts.log
    exit
fi


current_date=$(date +%Y%m%d-%H%M)
echo "Tsung log directory should be ${current_date}"
cmd='tsung -l /usr/local/tsung/ '$@
echo "Executin ${cmd} ..."
${cmd}
cd /usr/local/tsung/${current_date}/ && /usr/lib64/tsung/bin/tsung_stats.pl
