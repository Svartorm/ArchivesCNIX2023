#!/bin/sh

if [ $# -ne 1 ] || [ ! -r $1 ]; then
  exit 1
fi

IFS=''
while read -r line; do
  if [ ${#line} -gt 79 ]; then
    printf "%s\n" "$line"
  fi
done < "$1"

exit 0
