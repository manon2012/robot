#!/usr/bin/expect -f
spawn ssh diana@192.168.10.75 
expect "assword:"
send "welcome2agile\r"
interact
