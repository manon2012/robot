#!/bin/bash
#if TP lost connection! stop0, driver quit, run this.If not 0, error
if [ ! -f '/usr/local/bin/ethercat' ];then
chmod +x /opt/Ethercat/Runtime_Env/linux/x86_64/x64/Etherlab/4.16.18-rt12/bin/ethercat
cp /opt/Ethercat/Runtime_Env/linux/x86_64/x64/Etherlab/4.16.18-rt12/bin/ethercat /usr/local/bin -f
fi

count=`/usr/local/bin/ethercat master | grep Slaves | awk -F : '{print $2}'`
echo "Total $count slave(s) were found"
if [ $count -lt 1 ] || [ $count -gt 9 ];then
echo "doesn't match restrict rules,now quits"
exit 0
fi
while true
	do
	for j in {0x310,0x311,0x312,0x313}
	do
		for ((i=0; i<count; i++))
		do
			num=`/usr/local/bin/ethercat reg_read -p $i -t sm8 $j`
			echo "slave $i 's register $j = $num"
		done
	echo '-------------------------------------------------------'
	done

	for j in {0x300,0x301,0x302,0x303,0x304,0x305,0x306,0x307}
	do
		for ((i=0; i<count; i++))
		do
			num=`/usr/local/bin/ethercat reg_read -p $i -t sm8 $j`
			echo "slave $i 's register $j = $num"
		done
	echo '-------------------------------------------------------'
	done
	sleep 1
done
