#!/bin/bash

if [[ $# != 1 ]]; then
	echo "Usage: $0 <filename>" >&2
	exit 1
fi

height=$(wc -l "$1" | cut -d' ' -f1)
width=$(head -n1 "$1" | tr -d \\n | wc -c)

echo $height $width

head -c $((width+2)) /dev/zero | tr '\0' .; echo
while read -r line; do
	echo -n "."
	echo -n $line
	echo "."
done < "$1"
head -c $((width+2)) /dev/zero | tr '\0' '.'; echo

