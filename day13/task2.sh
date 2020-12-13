#!/bin/bash

if [[ $# != 1 ]]; then
	echo "Usage: $0 <data file>" >&2
	exit 1
fi

(head -n1 > /dev/null; sed 's/,/\n/g' | grep -vn x | sed 's/:/ /g') <"$1" | 

{
accumulated_rest=0
accumulated_multipler=1
while read -r rest multipler; do
	((--rest)) #grep prints line nums starting at 0
	((rest%=multipler))
	curr_val=$accumulated_rest
	while ((curr_val % multipler != rest)); do
		((curr_val+=accumulated_multipler))
	done
	accumulated_rest=$curr_val
	((accumulated_multipler*=multipler))
done
echo $accumulated_rest $accumulated_multipler $((accumulated_multipler-accumulated_rest))
}
