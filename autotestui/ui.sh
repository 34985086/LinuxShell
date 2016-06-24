#!/bin/sh
data_path=/mnt/user-data/uitest/uidata

if [ ! -d $data_path ];then
    mkdir $data_path
fi
rm -f $data_path/*
source /app/qtlib/qt_env.sh
ulimit -c unlimited
#if core dump, the core file will be save in $data_path directory
cd $data_path
./../uiaV0.0.001 >$data_path/uiaLog.txt 2>&1 &
pidOfUia=$!
echo "pidOfUia=$pidOfUia"
sleep 0.5
./../ui -qws >$data_path/uiLog.txt 2>&1 &
pidOfUi=$!
sleep 5

echo "pidOfUi=$pidOfUi"
cat /proc/$pidOfUi/maps > $data_path/maps
./../autosendkey.sh >$data_path/keyLog.txt 2>&1 &
pidOfSendKey=$!
echo "pidOfSendKey=$pidOfSendKey"

ps -A | grep "$pidOfUi"
state=$?
while [ $state -eq 0 ];
do
	sleep 1
	state=`ps -A | grep "$pidOfUi" >/dev/null`
	if [ $state -eq 1 ];then
		echo "ui process has exceptions"
	    kill -9 $pidOfUia && echo "kill uiaV0.0.001"
		kill -9 $pidOfSendKey && echo "kill autosendkey.sh"
	else
		echo "ui process is running"
	fi
done &

echo "Test environment done"


















