# the compiler to use
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

all: get_volume

default: get_volume

get_volume: get_volume.o bottle.o bottles_solver.o
	$(CC) -g -o get_volume get_volume.o bottle.o bottles_solver.o

get_volume.o:
	$(CC) -g -c get_volume.cpp

bottle.o:
	$(CC) -g -c bottle.cpp

bottle_solver.o:
	$(CC) -g -c bottle_solver.cpp

clean:
	rm *.o get_volume

