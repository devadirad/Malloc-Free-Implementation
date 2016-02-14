#Makefile for PA3

#Compiler
	CC=gcc

#CFLAGS 
	CFLAGS = -Wall -g

#Executable 
malloc: malloc.o 
	$(CC) -o malloc malloc.o

malloc.o:	malloc.c malloc.h
	$(CC) -c $(CFLAGS) malloc.c 
	
#clean
clean:
	rm -f *.o malloc
