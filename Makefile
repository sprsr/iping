C = gcc
CFLAGS = -Wall -Wextra -Werror

all: main

main: main.c
	$(CC) $(CFLAGS) -o main main.c

clean: 
	rm -f main
