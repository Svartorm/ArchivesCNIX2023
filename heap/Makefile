CC = gcc -g -fsanitize=address
CFLAGS = -std=c99 -Wall -Wextra -Werror -pedantic -Wvla

OBJS = add.o create.o del.o pop.o print.o
BIN = main

all: $(BIN)

library: $(BIN)
	ar csr libheap.a ${OBJS}

$(BIN): $(OBJS)


clean:
	$(RM) $(BIN) $(OBJS) libheap.a
