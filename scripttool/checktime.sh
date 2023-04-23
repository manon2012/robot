#!/bin/bash


while :
do
  TODAY=$(date +"Today is %A, %d of %B")
  TIMENOW=$(date +"The local time is %r")
  TIME_UK=$(TZ=BST date +"The time in the UK is %r")

 
  echo $TODAY
  echo $TIMENOW
  echo $TIME_UK
  sleep 0.1
done
