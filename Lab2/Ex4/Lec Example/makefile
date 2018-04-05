#Makefile

CC = gcc
CFLAGS = -Wall -O2 
# Wall enables all compiler’s warning message
# O2 – optimization: That breaks wraparound arithmetic
.c.o:
	$(CC) $(CFLAGS) -c $*.c  # -c source file
all: main.o hi bye     # compiling content 1)hi 2)bye

main.o: main.c main.h
	$(CC) -c main.c

hi: hi.o main.o
	$(CC) -o hi hi.o main.o

Bye: bye.o main.o
	$(CC) -o bye bye.o main.o

clean: rm -rf *.o core hi bye
