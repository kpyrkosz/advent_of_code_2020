#!/bin/bash

sed -nE 's/^([a-z]+).*: ([[:digit:]]+)-([[:digit:]]+) or ([[:digit:]]+)-([[:digit:]]+)$/\1 \2 \3 \4 \5/gp' < "$1" > ranges
grep ',' < "$1" | tr ',' ' ' > tickets
