#!/bin/bash
#countdown from 9 2 0
for i in `seq 9 -1 0`
	do
	   echo -n -e "\b$i"
	   sleep 1
	done
#echo “惊不惊喜\？"
echo -n -e "\b惊不惊喜？"
echo
