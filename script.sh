#!/bin/bash

# myarr=()
# myarr=($(shuf -i 0-$1))

# for i in ${!myarr[@]}; do
#     echo ${myarr[$i]}
# done

for (( count=1; count<100; count++ ))
	do
		ARG=$(./random_num 4);
		sleep 1
		# ARG=${myarr[@]:0:$1}
		if [[ "$(./push_swap $ARG | ./checker_Mac $ARG)" =~ "OK" ]]; then
			echo $ARG
			echo "$(./push_swap $ARG | wc -l)"
			# echo "KO"
		else
		 	echo "KO"
			echo $ARG
			echo "$(./push_swap $ARG | wc -l)"
		# 	echo $ARG
		fi
	done
