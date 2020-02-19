# PROGRAM:    Assign1 - makefile
# PROGRAMMER: Margaret Higginbotham
# LOGON ID:   z1793581
# DATE DUE:   January 24, 2020
#

CCFLAGS = -Wall -std=c++11

Assign1: Assign1.o
	g++ $(CCFLAGS) -o Assign1 Assign1.o

Assign1.o: Assign1.cpp
	g++ $(CCFLAGS) -c Assign1.cpp

clean:
	-rm *.o Assign1

