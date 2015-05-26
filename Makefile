CC=g++
CFLAGS=-Wall -std=c++11 -O3 -o exercise1

main: 
	$(CC) $(CFLAGS) main.cpp Calculator.cpp
