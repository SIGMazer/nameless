CC=gcc
CFLAGS=-Wall -Wextra -g 
CFILES= $(wildcard src/*.c)

all: $(CFILES)
	$(CC) $(CFLAGS) $(CFILES) -o main	 


