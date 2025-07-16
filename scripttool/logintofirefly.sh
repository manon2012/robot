#!/usr/bin/expect -f
spawn ssh firefly@192.168.8.200 
expect "assword:"
send "firefly\r"
interact
