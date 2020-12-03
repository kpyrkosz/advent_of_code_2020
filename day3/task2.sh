#!/bin/bash

#assumes the "task2.cpp" is built and available as "./a.out"
#your unique input file present as "input"

declare -a results
results=(
	$(./a.out 1 1 < input)
	$(./a.out 3 1 < input)
	$(./a.out 5 1 < input)
	$(./a.out 7 1 < input)
	$(./a.out 1 2 < input)
)

(printf '%s*' "${results[@]}"; echo 1) | bc
