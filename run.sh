#!/bin/bash

file_path=$1
time=$2

tput setaf 5
date "+[%H:%M:%S|%d-%m-%Y] Process running..🏃"
# tput setaf 1
tput sgr0
# echo ..
start=$(date +%s%N)

if ./$file_path;
then
	end=$(date +%s%N)
	tput setaf 5
	if [[ $time == "t" ]]
	then
		echo -n "$(date "+[%H:%M:%S|%d-%m-%Y]") Process ended taking "
		echo "scale=3; print $(($end - $start))/1000000000" | bc
		echo " sec."
	else
		echo "$(date "+[%H:%M:%S|%d-%m-%Y]") Process ended."
	fi
	tput sgr0
else
	end=$(date +%s%N)
	tput setaf 1
	if [[ $time == "t" ]]
	then
		echo -n "$(date "+[%H:%M:%S|%d-%m-%Y]") Process crached after "
		echo "scale=3; print $(($end - $start))/1000000000" | bc
		echo " sec with exit code 1."
	else
		echo "$(date "+[%H:%M:%S|%d-%m-%Y]") Process crached with exit code 1."
	fi
	tput sgr0
fi
