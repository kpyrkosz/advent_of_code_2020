#!/bin/bash

declare -A occurences

# $1-people count
process_group()
{
result=0
for i in {a..z}; do
	if [[ ${occurences[$i]} == $1 ]]; then
		((++result))
	fi
done
echo $result
}

people_count=0
sum=0
while read -r line; do
	if [[ -z $line ]]; then
		group_sum=$(process_group $people_count)
		((sum+=group_sum))
		people_count=0
		unset occurences
		declare -A occurences
	else
		for ((i=0;i<${#line};++i)); do
			((++occurences[${line:$i:1}]))
                        #echo ${line:$i:1} ${occurences[${line:$i:1}]}
		done
		((++people_count))
	fi
done < input
group_sum=$(process_group $people_count)
((sum+=group_sum))
echo $sum

