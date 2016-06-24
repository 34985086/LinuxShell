
#!/bin/sh
while true
do
    ui=`ps | grep ui | grep -v grep`;
    prism=`ps | grep PRISM | grep -v grep`;
    if [ "$ui" = "" -o "$prism" = "" ]; then
        killall PRISM ui >/dev/null 2>&1
        echo "no ui process, restart ui and PRISM!";
        ulimit -c unlimited
        export LD_LIBRARY_PATH=/root/:$LD_LIBRARY_PATH
        source /qt/qtlib/qt_env.sh
        /root/PRISM &
        /root/ui -qws -nomouse &
    fi
    sleep 2
done


