#!/bin/bash

max_seat_id=0

while read -r line; do
	as_binary=$(tr BFRL 1010 <<< $line)
	prefix=${as_binary:0:7}
	suffix=${as_binary:7:3}
	row=$(bc <<< "ibase=2; $prefix")
	column=$(bc <<< "ibase=2; $suffix")
	seat_id=$((row * 8 + column))
	if ((seat_id > max_seat_id)); then
		max_seat_id=$seat_id
	fi
done
echo $max_seat_id
