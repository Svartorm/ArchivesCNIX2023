CC = gcc -g -fsanitize=address
CFLAGS = -std=c99 -Wall -Wextra -Werror -pedantic -Wvla

SRC = $(shell echo *.c)
OBJS = $(SRC:.c=.o)
LIB = libdlist.a
BIN = main

all: $(BIN)

library: $(BIN)
	ar csr $(LIB) ${OBJS}

$(BIN): $(OBJS)


clean:
	$(RM) $(BIN) $(OBJS) $(LIB)
