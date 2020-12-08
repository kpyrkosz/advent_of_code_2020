#!/bin/bash

total_lines=$(wc -l "$1" | cut -f1 -d' ')
echo $total_lines
for ((i=1;i<$total_lines;++i)); do
	result=$(sed "${i}s/jmp/nop/" "$1" | ./preprocess.sh | ./a.out 2> /dev/null)
	if [[ $? == 0 ]]; then
		echo "Modifying jmp to nop at line $i fixes the program, acc: $result"
		exit 0
	fi
	result=$(sed "${i}s/nop/jmp/" "$1" | ./preprocess.sh | ./a.out 2> /dev/null)
        if [[ $? == 0 ]]; then
                echo "Modifying nop to jmp at line $i fixes the program, acc: $result"
                exit 0
        fi
done
echo "no luck?"
