#/bin/sh
# $Id: generate_histo.sh 2179 2013-05-28 22:16:51Z mesnierp $

. parameters

for i in *.txt; do
  b=`basename $i .txt`
  echo $i
  awk '/^HISTO/ {print $3}' $i | sort -n | uniq -c |
    awk -v N=$ITERATIONS '{print $2, $1 / N}' > $b.histo.dat
done
