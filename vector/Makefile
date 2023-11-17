CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -pedantic -Wvla

OBJS = vector.o
BIN = main

all: $(BIN)

library: $(BIN)
	ar csr libvector.a ${OBJS}

$(BIN): $(OBJS)

clean:
	$(RM) $(BIN) $(OBJS) libvector.a
