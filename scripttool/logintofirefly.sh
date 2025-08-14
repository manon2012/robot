#!/usr/bin/expect -f
spawn ssh firefly@192.168.1.10 
expect "assword:"
send "firefly\r"
interact
