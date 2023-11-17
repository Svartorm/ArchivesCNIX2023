#! /bin/sh

if [ $# -eq 1 ]; then
    [ -f $1 ] && cat $1 && exit 0
    echo "$1:\n\tis not a valid file"
    exit 2
fi
echo "Sorry, expected 1 argument but $# were passed"
exit 1
