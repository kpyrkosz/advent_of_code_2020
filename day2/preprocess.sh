#!/bin/bash

#assumes your unique input is in "input" file

sed -E 's/^([[:digit:]]+)-([[:digit:]]+) ([a-z]): ([a-z]+)/\1 \2 \3 \4/g' < input > cleaned
