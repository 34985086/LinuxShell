#include <stdio.h>
#include <stdlib.h>
#include "connection.h"

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Wrong Input Parameter \n");
		return 1;
	}
	int key = atoi(argv[1]);
	int type= atoi(argv[2]);
	if(type != UFNTP_KEY_DOWN && type != UFNTP_KEY_UP)
	{
		printf("Wrong key type \n");
		return 1;
	}
	createConnection();
	//printf("key=%d, type=%d \n", key, type);
	
	if(UFNTP_KEY_UP == type)
	{
		sendKeyUp(key);
	}else if(UFNTP_KEY_DOWN == type)
	{
		sendKeyDown(key);
	}
	closeConnection();
	return 0;
}