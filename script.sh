#!/bin/bash

# myarr=()
# myarr=($(shuf -i 0-$1))

# for i in ${!myarr[@]}; do
#     echo ${myarr[$i]}
# done

for (( count=1; count<100; count++ ))
	do
		ARG=$(./random_num 500);
		sleep 1
		# ARG=${myarr[@]:0:$1}
		if [[ "$(./push_swap $ARG | ./checker_Mac $ARG)" =~ "KO" ]]; then
			echo $ARG
			count=1000
			# echo "KO"
		else
		 	echo "OK"
		# 	echo $ARG
		fi
	done
