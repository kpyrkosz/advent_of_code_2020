#!/bin/bash

declare -a required_fields=(byr iyr eyr hgt hcl ecl pid)

{
while read -r line; do
	found=1
	for field in "${required_fields[@]}"; do
		regexp=".*$field.*"
		if ! [[ $line =~ $regexp ]]; then
			found=0
			break
		fi
	done
	if [[ $found == 1 ]]; then
		echo $line
	fi
done < cleaned
} | tee valid_passports | wc -l
