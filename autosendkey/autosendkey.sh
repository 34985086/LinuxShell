#!/bin/sh
keyTool=/mnt/user-data/keyTool
##############################
KEYUP=0
KEYDOWN=1

F1=4
F2=1
F3=2
F4=3
ENTER=15
BACK=9
UP=16
DOWN=19
LEFT=17
RIGHT=7
SCOPE=5
RECORD=20
HOLD=18
AUTO=6
MVA=11
VA=10
MVB=12
VB=8
STIME=23
NSTIME=13
POWER=21
MENU=14
WIFI=24
##############################

shortPress ()
{
   $keyTool $1 $KEYDOWN
   usleep 50000
   $keyTool $1 $KEYUP
}
#shortPress $F3
#sleep 2
num=0
while [ $num -ne -1 ]
do 
    shortPress $DOWN
    sleep 0.2
	num=`expr $num + 1`
    echo -n "$num  "
done











