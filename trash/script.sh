#!/bin/bash

# myarr=()
# myarr=($(shuf -i 0-$1))

# for i in ${!myarr[@]}; do
#     echo ${myarr[$i]}
# done

for (( count=1; count<100; count++ ))
	do
		ARG2=$(./random_num 2);
		ARG3=$(./random_num 3);
		ARG4=$(./random_num 4);
		ARG5=$(./random_num 5);
		ARG10=$(./random_num 10);
		ARG100=$(./random_num 100);
		ARG500=$(./random_num 500);
		# ARG10000=$(./random_num 10000);
		# if [[ "$(./push_swap $ARG2 | ./checker_Mac $ARG2)" =~ "KO" ]]; then
		#  	echo "------------KO-------------"
		# 	# echo $ARG2
		# fi
		if [[ "$(./push_swap $ARG3 | ./checker_Mac $ARG3)" =~ "KO" ]]; then
		 	echo "------------KO-------------"
			# echo $ARG3
		fi
		if [[ "$(./push_swap $ARG4 | ./checker_Mac $ARG4)" =~ "KO" ]]; then
		 	echo "------------KO-------------"
			# echo $ARG4
		fi
		if [[ "$(./push_swap $ARG5 | ./checker_Mac $ARG5)" =~ "KO" ]]; then
		 	echo "------------KO-------------"
			# echo $ARG5
		fi
		if [[ "$(./push_swap $ARG10 | ./checker_Mac $ARG10)" =~ "KO" ]]; then
		 	echo "------------KO-------------"
			# echo $ARG10
		fi
		if [[ "$(./push_swap $ARG100 | ./checker_Mac $ARG100)" =~ "KO" ]]; then
		 	echo "------------KO-------------"
			# echo $ARG100
		fi
		if [[ "$(./push_swap $ARG500 | ./checker_Mac $ARG500)" =~ "KO" ]]; then
		 	echo "------------KO-------------"
			# echo $ARG500
		fi
		# echo "OK"
		# echo "5: $(./push_swap $ARG3 | wc -l)"
		# if [[ "$(./push_swap $ARG10000 | ./checker_Mac $ARG10000)" =~ "KO" ]]; then
		#  	echo "------------KO-------------"
		# 	echo $ARG10000
		# fi

		# echo "2: $(./push_swap $ARG2 | wc -l)"
		# echo $ARG2
		echo "3: $(./push_swap $ARG3 | wc -l)"
		# echo $ARG3
		echo "4: $(./push_swap $ARG4 | wc -l)"
		# echo $ARG4
		echo "5: $(./push_swap $ARG5 | wc -l)"
		# echo $ARG5
		echo "10: $(./push_swap $ARG10 | wc -l)"
		# echo $ARG10
		echo "100: $(./push_swap $ARG100 | wc -l)"
		# echo $ARG100
		echo "500: $(./push_swap $ARG500 | wc -l)"
		# echo $ARG500
		# echo "10000: $(./push_swap $ARG10000 | wc -l)"
		echo " "


		sleep 2
	done
