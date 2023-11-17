#! /bin/sh

if [ $# -ne 0 ]
then
    rm  *.$1
else
    rm  *.txt
fi
