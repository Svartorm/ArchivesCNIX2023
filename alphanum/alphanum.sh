#!/bin/sh

while read -r input; do
    if [ -z "$input" ]; then
        echo "it is empty"
    elif echo "$input" | grep -q "^[a-zA-Z]*$"; then
        echo "it is a word"
    elif echo "$input" | grep -q "^[0-9]$"; then
        echo "it is a digit"
    elif echo "$input" | grep -q "^[0-9][0-9]*$"; then
        echo "it is a number"
    elif echo "$input" | grep -q "^[a-zA-Z0-9]*$"; then
        echo "it is an alphanum"
    else
        echo "it is too complicated"
        exit 0
    fi
done