# the compiler to use
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall -std=c++11

all: get_volume

default: get_volume

get_volume: get_volume.o bottle.o bottles_solver.o arg_check.o
	$(CC) -g -std=c++11 -Wall -o get_volume get_volume.o bottle.o bottles_solver.o arg_check.o

get_volume.o:
	$(CC) -g -std=c++11 -c get_volume.cpp

bottle.o:
	$(CC) -g -std=c++11 -c bottle.cpp

bottle_solver.o:
	$(CC) -g -std=c++11 -c bottle_solver.cpp

arg_check.o:
	$(CC) -g -std=c++11 -c arg_check.cpp

unit_test: unit_test.o
	$(CC) -g -o unit_test unit_test.o arg_check.o bottle.o

unit_test.o:
	$(CC) -g -std=c++11 -c unit_test.cpp

clean:
	rm *.o get_volume unit_test

