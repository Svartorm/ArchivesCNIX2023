#! /bin/sh

sed -n 's/^[A-Za-z0-9_]\+ [A-Za-z0-9_ *]*([A-Za-z0-9_, *]*)/&;/p' "$1"
