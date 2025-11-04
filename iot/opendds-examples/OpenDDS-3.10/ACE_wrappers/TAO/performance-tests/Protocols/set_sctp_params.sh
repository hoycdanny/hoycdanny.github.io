#!/bin/sh
# $Id: set_sctp_params.sh 2179 2013-05-28 22:16:51Z mesnierp $

# $Id: set_sctp_params.sh 2179 2013-05-28 22:16:51Z mesnierp $

B_PROC=/proc/sys/net/ipv4

CONF_PATH=/groups/pces/uav_oep/oomworks/openss7-debug/TAO/performance-tests/Protocols
. ${CONF_PATH}/sctp_params.conf

for i in $SETTINGS; do
	eval "echo \"echo \$$i > \$B_PROC/\${PREFIX}${i}\""
	eval "echo \$$i > \$B_PROC/\${PREFIX}${i}"
done
