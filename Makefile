OBJS = BrainFuck.o
CC = clang++
STD= -std=c++14
CFLAGS = -Wall -Werror -c
LFLAGS = -Wall -Werror

getfucked : $(OBJS) getfucked.cpp
	$(CC) $(STD) $(LFLAGS) $(OBJS) getfucked.cpp -o getfucked

BrainFuck.o: BrainFuck.cpp BrainFuck.h
	$(CC) $(STD) $(CFLAGS) BrainFuck.cpp

clean:
	rm *.o getfucked