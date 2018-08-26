CC=gcc
CFLAGS= -I.
BIN = ./bin/
SRC= $(wildcard ./src/*.c)
SRC += main.c

OBJ=$(SRC:.c=.o)

fileDump : $(OBJ)
	$(CC)  -o $(BIN)$@ $^ $(CFLAGS)

.clean:
	rm -f $(OBJ)	