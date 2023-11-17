CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -pedantic -Wvla

OBJS = tree.o print_tree.o bst.o
BIN = main

all: $(BIN)

library: $(BIN)
	ar csr libbinary_tree.a ${OBJS}

$(BIN): $(OBJS)


clean:
	$(RM) $(BIN) $(OBJS) libbinary_tree.a
