#!/bin/bash
x="foo"
y=$x"bar"
y=123
echo y

x:="foo"
y:=$x"bar"
y:=123
echo y
