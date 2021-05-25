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

C_RESET="\e[0;0m"
C_BOLD="\e[1m"
C_RED="\e[0;31m"
C_GREEN="\e[0;32m"
C_YELLOW="\e[0;33m"
C_GRAY="\e[0;37m"
C_BLUE="\e[0;34m"
C_LGRAY="\e[0;90m"
C_LRED="\e[0;91m"
C_LGREEN="\e[0;92m"
C_LBLUE="\e[0;94m"
C_BGRAY="\e[1;30m"
C_BRED="\e[1;31m"
C_BGREEN="\e[1;32m"
C_BYELLOW="\e[1;33m"
C_BBLUE="\e[1;34m"

CHECKER=./checker
PUSH_SWAP=./push_swap
TMP=./test/test.tmp

print_stat() {
	printf "   $C_GRAY$1$C_RESET $C_BOLD$2$C_RESET"
}

test() {
	printf "${C_BBLUE}$1${C_RESET}\n"

	too_many_ops=0
	bad_ops=0
	average=()

	for i in $( seq 1 $3 )
	do
		arg=`ruby -e "puts (1..$1).to_a.shuffle.join(' ')"`
		$PUSH_SWAP $arg > $TMP 2> /dev/null
		ops=`wc -l < $TMP`
		ok=`$CHECKER $arg < $TMP 2> /dev/null`

		printf "${C_LGRAY}%-5i" ${i}

		# tmp=$(($average + $ops))
		average[i]=$(($ops))

		if [[ $((ops)) -lt $2 ]]; then
			status=${C_LGREEN}
		elif [[ $((ops)) -eq $2 ]]; then
			status=${C_BYELLOW}
		else
			status=${C_BRED}
			too_many_ops=$(($too_many_ops + 1))
		fi

		printf "${status}%2i$C_RESET " $((ops))

		if [[ $ok == "OK" ]]; then
			printf "${C_GREEN}%5s$C_RESET" "OK"
		else
			printf "${C_RED}%5s${C_RESET}\t${arg}" "KO"
			bad_ops=$(($bad_ops + 1))
		fi

		echo
	done

	avg=$(IFS='+'; bc<<<"scale=1;(${average[*]})/${#average[@]}")

	if [[ ${avg::1} == "." ]]; then
		avg="0"$avg
	fi

	printf "$C_YELLOW$1"
	print_stat "avg" $avg
	print_stat "fail" $too_many_ops
	print_stat "ko" $bad_ops
	echo
	echo
}

touch $TMP

test 3 4 10
test 5 12 10
# test 6 0 8

rm $TMP
