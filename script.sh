#!/bin/bash

# myarr=()
# myarr=($(shuf -i 0-$1))

# for i in ${!myarr[@]}; do
#     echo ${myarr[$i]}
# done

for (( count=1; count<1000; count++ ))
	do
		ARG=$(./random_num 10);
		sleep 1
		# ARG=${myarr[@]:0:$1}
		if [[ "$(./a.out $ARG | ./checker_Mac $ARG)" =~ "KO" ]]; then
			echo $ARG
			# echo "OK"
		else
		 	echo "OK"
		# 	echo $ARG
		fi
	done
