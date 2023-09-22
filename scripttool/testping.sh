#!/bin/bash

count=0
#for i in `seq 1 3`
for i in {1..10}
do
  echo $i
  
  ping -c 1  192.168.1.$i &> /dev/null
#ping -c 1  192.168.10.75  > /dev/null
#ifconfig

if [ $? -eq 0 ]
 then
    echo "ping ok"
   # count+=1
   #count=$((count+1))
   ((count+=1))
   echo "192.168.1.$i" >> pingok.txt

else
    echo "ping not ok"
   echo "192.168.1.$i" >> pingnotok.txt
fi    

done
echo "total ping ok count is:" $count
