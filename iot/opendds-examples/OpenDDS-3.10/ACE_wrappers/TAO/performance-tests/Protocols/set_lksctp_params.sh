#!/bin/sh
# $Id: set_lksctp_params.sh 2179 2013-05-28 22:16:51Z mesnierp $

# $Id: set_lksctp_params.sh 2179 2013-05-28 22:16:51Z mesnierp $

B_PROC=/proc/sys/net/sctp

CONF_PATH=/groups/pces/uav_oep/oomworks/lksctp-debug/TAO/performance-tests/Protocols
. ${CONF_PATH}/lksctp_params.conf

for i in $SETTINGS; do
	eval "echo \"echo \$$i > \$B_PROC/\${PREFIX}${i}\""
	eval "echo \$$i > \$B_PROC/\${PREFIX}${i}"
done
