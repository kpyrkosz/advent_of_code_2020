#!/bin/bash

if [[ $# != 1 ]]; then
	echo "Usage: $0 <filename>"
	exit 1
fi
grep -v "no other" < "$1" | tr -d ',.' | sed 's/ bags//g;s/ bag//g;s/ contain//g' | sed -E 's/([a-z]) ([a-z])/\1_\2/g' | awk '{print (NF-1)/2, $0}'
