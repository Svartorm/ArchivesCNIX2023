#!/bin/sh

# Get user ids from /etc/passwd, sort them in descending order, and remove duplicates
ids=$(cut -d: -f3 /etc/passwd | sort -rn)

# Remove duplicate user ids
prev_id=""
for id in $ids; do
    if [ "$id" != "$prev_id" ]; then
        echo "$id"
    fi
    prev_id="$id"
done
