#! /bin/bash
#Set colors
RED='\033[0;31m'
GREEN='\033[0;32m'
NORMAL='\033[0m'
#Set number of iterations
if [ $# -eq 0 ]
then
	ITER_NUM=25
else
	ITER_NUM=$1
fi
#function test_push_swap
#{
#	echo -n "$1 number test: "
	let "max = $1 / 2 - 1"
	let "min = ($max + 1) * (-1)"
#	I=0
#	SUM=0
#	while [ $I -lt $ITER_NUM ]
#	do
		ARG=`ruby -e "puts ($min..$max).to_a.shuffle.join(' ')"`
		echo $ARG
		#OPERATIONS="$( )"
		./push_swap $ARG
#		OPERATIONS_COUNT=$(echo "$OPERATIONS" | wc -l)
#		RESULT="$(echo "$OPERATIONS" | ./checker $ARG)"
#		if [[ "$RESULT" != "[OK]" && "$RESULT" != "" ]]
#		then
#			echo -e ${RED}$RESULT${NORMAL}
#			return -1
#		fi
#		let "SUM += $OPERATIONS_COUNT"
#		let "I += 1"
#	done
#	echo -e ${GREEN}[OK]${NORMAL}
#	let "RES = $SUM / $ITER_NUM"
#	echo -e "Numbers of operations: $RES\n"
#	return $RES
#}
#test_push_swap 0
#test_push_swap 5
#test_push_swap 25
#test_push_swap 50
#test_push_swap 100
#test_push_swap 500

exit 0
