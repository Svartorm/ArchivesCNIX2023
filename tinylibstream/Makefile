CC = gcc -g 
CFLAGS = -std=c99 -Wall -Wextra -Werror -pedantic -Wvla

SRC = $(wildcard src/*.c)
OBJS = $(SRC:.c=.o)
BIN = main

all: $(BIN)

library: $(BIN)
	ar csr libstream.a ${OBJS}

$(BIN): $(OBJS)

stdin: stdin_buffering_test.c
	$(CC) $(CFLAGS) -o $@ $^

stdout: stdout_buffering_test.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(BIN) $(OBJS) libstream.a
