#CC=arm-arago-linux-gnueabi-gcc
#CXX=arm-arago-linux-gnueabi-g++
CC=gcc
#CC		   :=gcc
#CXX		   :=g++
LD         := ld

C_SOURCE   := $(wildcard ./*.c)


OBJS_C     := $(patsubst %.c,%.o,$(C_SOURCE))
OBJS_CPP   := $(patsubst %.cpp,%.o,$(CPP_SOURCE))
OBJS       := ${OBJS_C} ${OBJS_CPP}

###########################################
all:${OBJS}
	$(CC) -o keyTool ${OBJS}

%.o: %.c	
	$(CC) $(CFLAGS)  -I. -c $< -o $@ 
clean:
	rm  -f ./${OBJS}

