#/bin/sh
# $Id: generate_histo.sh 2179 2013-05-28 22:16:51Z mesnierp $

for i in *.txt; do
  b=`basename $i .txt`
  echo $i
  awk '/^HISTO/ {print $3}' $i | sort -n | uniq -c |
    awk '{print $2, 100.0 * $1 / 20000.0}' > $b.histo.dat
done
