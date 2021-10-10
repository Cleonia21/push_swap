#!/bin/bash

# myarr=()
# myarr=($(shuf -i 0-$1))

# for i in ${!myarr[@]}; do
#     echo ${myarr[$i]}
# done

for (( count=1; count<100; count++ ))
	do
		sleep 1
		ARG=$(./random_num 3);
		if [[ "$(./push_swap $ARG | ./checker_Mac $ARG)" =~ "OK" ]]; then
			echo "$(./push_swap $ARG | wc -l)"
		else
		 	echo "KO"
			echo $ARG
		fi
	done
