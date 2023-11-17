#! /bin/sh

# Test if the number of arguments is 2
if [ $# -ne 2 ]; then
    exit 1
fi

# Get the arguments
filename="$1"
line_number="$2"

# Test if line number is a number
if ! [ $line_number -eq $line_number ] 2>/dev/null; then
    exit 1
fi

# Test is line number is positive
if [ "$line_number" -lt 1 ]; then
    exit 1
fi

# Test if file exists
if ! [ -f "$filename" ]; then
    exit 1
fi

# Get the line from the file
line=$(sed -n "${line_number}p" "$filename")

# Test if line is empty
if [ -z "$line" ]; then
    exit 1
fi

# Get the name and nick from the line
column2=$(echo "$line" | sed 's/^[^;]*;//;s/;.*//')
column3=$(echo "$line" | sed 's/^[^;]*;[^;]*;//;s/;.*//')

# Test if name and nick are empty
if [ -z "$column2" ] || [ -z "$column3" ]; then
    exit 1
fi

# Print the name and nick
echo "${column2} is ${column3}"