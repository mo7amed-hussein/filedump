CC=gcc
CFLAGS= -I.
BIN = ./bin/

fileDump : main.c
	$(CC) main.c -o $(BIN)fileDump $(CFLAGS)

.clean:
	rm -r *.o	