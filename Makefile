
CC=g++
CFLAGS=-I.

hello: hello.cpp lib_functions.cpp
	${CC} ${CFLAGS} -o a.out hello.cpp lib_functions.cpp

# OBJS = hello.cpp
# default: hello
#$(CC) $(CFLAGS) $(LFLAGS) -o hello $(OBJS) $(LIBS)
# ${OBJS}: %.o :  %.c
# ${CC} -c ${CFLAGS} ${LFLAGS} ${INCLUDES} ${@:.o=.c}
