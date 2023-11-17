CC = gcc -g -fsanitize=address
CFLAGS = -std=c99 -Wall -Wextra -Werror -pedantic -Wvla

OBJS = fifo_access.o fifo_setup_destroy.o
BIN = main
LIB = libfifo.a

all: $(BIN)

library: $(BIN)
	ar csr $(LIB) ${OBJS}

$(BIN): $(OBJS)


clean:
	$(RM) $(BIN) $(OBJS) $(LIB)
