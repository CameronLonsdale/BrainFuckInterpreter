OBJS = getfucked.o
CC = clang++
STD= -std=c++14
CFLAGS = -Wall -Werror -c
LFLAGS = -Wall -Werror

getfucked : $(OBJS)
	$(CC) $(STD) $(LFLAGS) $(OBJS) -o getfucked

getfucked.o: getfucked.cpp getfucked.h
	$(CC) $(STD) $(CFLAGS) getfucked.cpp

clean:
	rm *.o getfucked