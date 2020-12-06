#!/bin/bash

sum=0

while read -r line; do
	uniq_chars=$(grep -o . <<< $line | sort -u | wc -l)
	echo $line $uniq_chars
	((sum+=uniq_chars))
done < <(sed 's/^$/-/g' < input | tr -d \\n | sed 's/-/\n/g'; echo)
echo $sum
