#!/bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocca <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 21:22:55 by lrocca            #+#    #+#              #
#    Updated: 2021/05/18 21:22:55 by lrocca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NC="\e[0m"
RED="\e[0;91m"
GREEN="\e[0;92m"
BLUE="\e[0;94m"

CHECKER=./checker
PUSH_SWAP=./push_swap
TMP=./test/test.tmp

test() {
	printf "${BLUE}\t$1${NC}\n"
	for i in $( seq 1 $3 )
	do
		arg=`ruby -e "puts (1..$1).to_a.shuffle.join(' ')"`
		$PUSH_SWAP $arg > $TMP
		ops=`wc -l < $TMP`
		ok=`$CHECKER $arg < $TMP`
		if [[ $((ops)) -lt ${2} ]] && [[ $ok == "OK" ]]
		then
			printf "${GREEN}OK$NC "
		else
			echo
			printf "${RED}KO${NC} --> Operations: $ops\n"
			printf "\t\t\t$arg\n"
		fi
	done
	echo
}

touch $TMP

test 3 4 8
test 5 12 8

rm $TMP
