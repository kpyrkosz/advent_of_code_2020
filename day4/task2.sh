#!/bin/bash

sed -E 's/cid:[[:digit:]]+[ ]?//g' valid_passports |
while read -r line; do echo $(echo $line | tr \  \\n | sort) ; done |
sed 's/[a-z]\+://g' |
while read -r byr ecl eyr hcl hgt iyr pid; do
	if ((byr < 1920 || byr > 2002)); then continue; fi
	if ((iyr < 2010 || iyr > 2020)); then continue; fi
	if ((eyr < 2020 || eyr > 2030)); then continue; fi
	hgt_cm=$(grep -Eo '[[:digit:]]+cm' <<< $hgt | sed 's/cm//')
        hgt_in=$(grep -Eo '[[:digit:]]+in' <<< $hgt | sed 's/in//')
	if [[ -z $hgt_cm && -z $hgt_in ]]; then continue; fi
        if ! (( (hgt_cm >= 150 && hgt_cm <= 193) || (hgt_in >= 59 && hgt_in <= 76) )); then continue; fi
	if ! [[ $hcl =~ ^\#[a-f0-9]{6}$ ]]; then continue; fi
	if ! [[ $ecl == "amb" || $ecl == "blu" || $ecl == "brn" || $ecl == "gry" || $ecl == "grn" || $ecl == "hzl" || $ecl == "oth" ]]; then continue; fi
	if ! [[ $pid =~ ^[0-9]{9}$ ]]; then continue; fi
        echo "bada bing bada boom"
done | wc -l
