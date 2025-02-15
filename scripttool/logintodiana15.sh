#!/usr/bin/expect -f
spawn ssh diana@192.168.15.202 
expect "assword:"
send "welcome2agile\r"
interact
