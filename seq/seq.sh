#! /bin/sh

# Args nb is not correct
if [ $# -ne 3 ]; then
    >&2 echo "Usage: ./seq.sh FIRST INCREMENT LAST"
    exit 1
fi

# The argument INCREMENT must not be zero.
if [ $2 -eq 0 ]; then
    exit 1
fi

# FIRST == LAST
if [ $1 -eq $3 ]; then
    echo $1
    exit 0
fi

# FIRST > LAST
# INCREMENT < 0
if [ $1 -gt $3 ]; then
    if [ $2 -ge 0 ]; then
        exit 1
    fi
    # Display numbers in descending order
    i=$1
    while [ $i -ge $3 ]; do
        echo $i
        i=$(($i + $2))
    done
    exit 0
fi

# FIRST < LAST
# INCREMENT > 0
if [ $1 -lt $3 ]; then
    if [ $2 -lt 0 ]; then
        exit 1
    fi
    # Display numbers in ascending order
    i=$1
    while [ $i -le $3 ]; do
        echo $i
        i=$(($i + $2))
    done
    exit 0
fi

exit 1