#!/bin/bash
#!/bin/bash

var=`df -h | grep tmpfs`
var=`top -n 1| grep TeachPendantUI`
echo $var
