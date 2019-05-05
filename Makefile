CC=gcc
CFLAGS=

.PHONY: all clean

all: hasher.exe

hasher.exe: hasher.c
	$(CC) $(CFLAGS) hasher.c -lcrypto -lssl -fopenmp -o hasher.exe 

clean:
	rm -rf *.o *.exe
