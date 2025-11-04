#!/bin/sh
# $Id: generate_acc.sh 2179 2013-05-28 22:16:51Z mesnierp $

. parameters

for t in $TYPES; do
  for i in $t.*.dat; do
    b=`basename $i .dat`
    awk 'BEGIN {
           s = 0;
         }
         {
           s += $2;
           print $1, s
         }' $i > $b.acc.dat;
    echo $i
  done
done
