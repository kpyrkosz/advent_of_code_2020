#!/bin/bash

if [[ $# != 1 ]]; then
	echo "Usage: $0 <filename>"
	exit 1
fi
grep -v "no other" < "$1" | tr -d ',.' | sed 's/ bags//g;s/ bag//g;s/ contain//g' | sed -E 's/([a-z]) ([a-z])/\1_\2/g;s/ [0-9]//g' | awk '{print NF, $0}'
