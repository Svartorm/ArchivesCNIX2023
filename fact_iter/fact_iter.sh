#! /bin/sh

[ $# -ne 1 ] && exit 1

f=1
n=$1
while [ $n -gt 1 ]
do
  f=$((f * $n))
  n=$(($n - 1))
done

echo $f
