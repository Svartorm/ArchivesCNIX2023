#!/bin/sh

if [ $# -eq 0 ]; then
  while IFS='' read input; do
      echo "$(($input))"
  done
else
    echo "$(($1))"
fi
