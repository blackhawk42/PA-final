CC=gcc
CFLAGS=

.PHONY: all clean

all: hasher.exe

hasher.exe: hasher.c
	$(CC) $(CFLAGS) -o hasher.exe hasher.c

clean:
	rm -rf *.o *.exe