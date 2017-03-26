#declare variable
CC = g++

CFLAGS = -c -std=c++11
all: sprint

sprint: Components.o Robot_part.o Main.o Model.o
	$(CC) Main.o Robot_part.o Components.o Model.o -o sprint.out

Components.o: Components.h Components.cpp
	$(CC) $(CFLAGS) Components.cpp 
Robot_part.o: Robot_part.h Robot_part.cpp
	$(CC) $(CFLAGS) Robot_part.cpp
Main.o: Main.cpp
	$(CC) $(CFLAGS) Main.cpp
Model.o: Model.cpp
	$(CC) $(CFLAGS) Model.cpp
run:
	./sprint.out
clean: 
	rm -rf *o *.h.gch *.out game.out




