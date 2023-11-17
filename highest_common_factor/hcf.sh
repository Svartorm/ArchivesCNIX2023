#! /bin/sh

[ $# -ne 2 ] && echo Usage: ./hcf.sh num1 num2 && exit 1
[ $2 -eq 0 ] && echo Exception: division by 0 && exit 2
uwu=$1
owo=$2
while [ $owo -ne 0 ]
do
    r=$(($uwu % $owo))
    uwu=$owo
    owo=$r
done

echo $uwu
