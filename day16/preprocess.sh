#!/bin/bash


(while read -r line; do
	if [[ $line == "nearby tickets:" ]]; then
		break
	fi
done
grep -oE '[[:digit:]]+') < "$1" > vals
grep -oE '([[:digit:]]+)-([[:digit:]]+)' < "$1" > ranges
