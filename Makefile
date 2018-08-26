CC=gcc
CFLAGS= -I. -lm
BIN = ./bin/
SRC= $(wildcard ./src/*.c)
SRC += main.c

OBJ=$(SRC:.c=.o)

fileDump : $(OBJ)
	$(CC)  -o $(BIN)$@ $^ $(CFLAGS)

.phony:

clean:
	rm -f $(OBJ)	