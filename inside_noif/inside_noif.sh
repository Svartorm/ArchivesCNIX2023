#! /bin/sh

[ $# -eq 1 ] &&
    {
        [ -f $1 ] && cat $1 && exit 0
        echo "$1:\n\tis not a valid file"
        exit 2
    }
echo "Sorry, expected 1 argument but $# were passed"
exit 1
