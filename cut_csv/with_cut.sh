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

# Get the names and nicks from the file
names=$(cut -d ';' -f 2 "$filename")
nicks=$(cut -d ';' -f 3 "$filename")

# Count the number of lines in the file
num_lines=$(wc -l < "$filename")

# Test if line number is greater than the number of lines in the file
if [ "$line_number" -gt "$num_lines" ]; then
    exit 1
fi

# Get the name and nick from the line number
name=$(echo "$names" | head -n "$line_number" | tail -n 1)
nick=$(echo "$nicks" | head -n "$line_number" | tail -n 1)

# Test if name and nick are empty
if [ -z "$name" ] || [ -z "$nick" ]; then
    exit 1
fi

# Print the name and nick
echo "$name is $nick"
exit 0