#! /bin/sh

for f in "$@"
do
    if [ -d "$f" ]
    then
        echo "$f: directory"
    else
        if [ -e "$f" ]
        then
            echo "$f: file"
        else
            echo "$f: unknown"
        fi
    fi
done
