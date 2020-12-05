#!/bin/bash

sorted=$(while read -r line; do
	as_binary=$(tr BFRL 1010 <<< $line)
	prefix=${as_binary:0:7}
	suffix=${as_binary:7:3}
	row=$(bc <<< "ibase=2; $prefix")
	column=$(bc <<< "ibase=2; $suffix")
	seat_id=$((row * 8 + column))
	echo $seat_id
done | sort -n)

#solution below is VERY unoptimal but fine for small data
min=$(head -n1 <<< $sorted)
max=$(tail -n1 <<< $sorted)
sum_of_range=$(seq -s'+' $min $max | bc)
sum_of_seats=$( (tr \\n + <<< $sorted; echo 0) | bc)
echo $((sum_of_range - sum_of_seats))
