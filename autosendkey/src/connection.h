#ifndef SIMCOMM_H
#define SIMCOMM_H
#include "datatypedefs.h"

#define NULL_DEVICE_LINUX -1

typedef struct {
    INT32S    tv_sec;		/* seconds */
    INT32S    tv_usec;	    /* microseconds */
} timeval_t;

typedef struct {
    timeval_t time;
    INT16U type;
    INT16U code;
    INT32S value;
} input_event_t;

#define    UFNTP_BUTTON_KNOB_TYPE       1
#define    UFNTP_KEY_DOWN               1
#define    UFNTP_KEY_UP                 0

void sendKeyDown(int v);
void sendKeyUp(int v);

INT8S createConnection(void);
void closeConnection(void);

#endif // SIMCOMM_H
