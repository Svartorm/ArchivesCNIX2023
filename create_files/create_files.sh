#! /bin/sh

touch ' '
touch '\'
touch -- '--'
touch '|'
touch '"'
touch "'"
touch -- "--\$i*'\"\\"
touch '# Exams are fun!'
touch -- ';`kill -9 0`'
mkdir -p $(seq -s "/" 50)
touch "$(seq -s "/" 50)/farfaraway"
