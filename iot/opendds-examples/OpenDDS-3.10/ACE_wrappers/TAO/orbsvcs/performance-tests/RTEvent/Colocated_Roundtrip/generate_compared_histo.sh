#!/bin/sh
# $Id: generate_compared_histo.sh 2179 2013-05-28 22:16:51Z mesnierp $

. parameters

for j in copy_on_write copy_on_read delayed;
do
    for i in $NCONSUMERS;
    do
        ./compare_histo.pl ec_locking.$j.$i.16.histo.dat ec_locking.$j.32.16.histo.dat >$j.$i.dat;
    done;
done

