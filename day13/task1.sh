#!/bin/bash

if [[ $# != 1 ]]; then
	echo "Usage: $0 <data file>" >&2
	exit 1
fi

sed 's/x,//g;s/,/\n/g' < "$1" |
{
read -r depart
best_diff=$depart
best_bus=0
while read -r num; do
	diff=$((num - (depart % num)))
	if ((diff < best_diff)); then
		best_diff=$diff
		best_bus=$num
	fi
done
echo $best_diff $best_bus $((best_diff*best_bus))
}
