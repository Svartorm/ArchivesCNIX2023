#! /bin/sh

FN="default"
N=1
EXT=txt

while [ $# -ne 0 ]
do
    case "$1" in
        -f|--filename)
            FN=$2
            shift && shift
            ;;
        -n|--number)
            N=$2
            shift && shift
            ;;
        -e|--extension)
            EXT=$2
            shift && shift
            ;;
        *)
            exit 1
            ;;
    esac
done

for i in $(seq $N)
do
    touch -- "$FN-$i.$EXT"
done
