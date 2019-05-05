CC=gcc
CFLAGS=

.PHONY: all clean

all: hasher_concurrent.exe hasher_serial.exe

hasher_concurrent.exe: hasher_concurrent.c
	$(CC) $(CFLAGS) hasher_concurrent.c -lcrypto -lssl -fopenmp -o hasher_concurrent.exe 

hasher_serial.exe: hasher_serial.c
	$(CC) $(CFLAGS) hasher_serial.c -lcrypto -lssl -o hasher_serial.exe 

clean:
	rm -rf *.o *.exe
