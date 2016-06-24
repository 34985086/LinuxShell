#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include "connection.h"

static int connected = FALSE;
static int hPipe     = NULL_DEVICE_LINUX;
const char *myfifo   = "/tmp/simkbd";

INT8S createConnection(void)
{
    int ret = 0;

    if(connected)
    {
        return TRUE;
    }

    if(NULL_DEVICE_LINUX == hPipe)
    {
        if (NULL_DEVICE_LINUX == access(myfifo, F_OK))
        {
            ret = mkfifo(myfifo, 0666);
            if(NULL_DEVICE_LINUX == ret)
            {
                printf("Create fifo failed\n");
                return FALSE;
            }
            //printf("Create fifo\n");
        }
        hPipe = open(myfifo, O_RDWR);
        if(NULL_DEVICE_LINUX == hPipe)
        {
            printf("Open myfifo failed\n");
            return FALSE;
        }
        else
        {
            connected = TRUE;
            //printf("Connect myfifo\n");
            return TRUE;
        }
    }
    
    return FALSE;
}

void closeConnection(void)
{
    connected = FALSE;
    if(NULL_DEVICE_LINUX != hPipe)
    {
        close(hPipe);
        //unlink(myfifo);
        //printf("remove myfifo\n");
        hPipe = NULL_DEVICE_LINUX;
    }
}

void sendToPipe(input_event_t *buf)
{
    if (!connected)
    {
        return;
    }

    int realNum = 0;
    realNum = write(hPipe, buf, sizeof(input_event_t));
   
    if (realNum != sizeof(input_event_t))
    {
        printf("WriteFile failed\n");
    }

}
void sendKeyDown(int v)
{
    input_event_t event;
    struct timeval current;
        
    gettimeofday(&current, NULL);
        
    event.time.tv_sec = current.tv_sec;
    event.time.tv_usec = current.tv_usec;
    event.type = UFNTP_BUTTON_KNOB_TYPE;
    event.code = v;
    event.value = UFNTP_KEY_DOWN;
       
    sendToPipe(&event);
}


void sendKeyUp(int v)
{
    input_event_t event;
    struct timeval current;
        
    gettimeofday(&current, NULL);
        
    event.time.tv_sec = current.tv_sec;
    event.time.tv_usec = current.tv_usec;
    event.type = UFNTP_BUTTON_KNOB_TYPE;
    event.code = v;
    event.value = UFNTP_KEY_UP;
       
    sendToPipe(&event);
}
