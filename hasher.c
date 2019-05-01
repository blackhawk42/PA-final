#include <stdio.h>
#include <stdlib.h>

#include <openssl/evp.h>

#define BUFFER_SIZE 256
#define SUM_SIZE 20

#define ITER_COUNT 1000

void print_help() {
    fprintf(stderr, "use: hasher.exe PASS_LIST\n");
    fprintf(stderr, "\nPASS_LIST is a list of passwords to hash\n");
}

// Search a string for a newline and, if one found, replace it with a NULL terminator.
// Return 1 if a newline was replaced and 0 otherwise.
int null_terminate_newline(char *str) {
    while(*str != '\0') {
        if(*str == '\n') {
            *str = '\0';
            return 1;
        }

        str++;
    }

    return 0;
}

void hash_line(char *pass) {
    null_terminate_newline(pass);

	unsigned char sum_buff[SUM_SIZE];

	PKCS5_PBKDF2_HMAC(pass, -1,
			NULL, 0, ITER_COUNT,
			EVP_sha1(),
			SUM_SIZE, sum_buff);

	int i;
	for(i = 0; i < SUM_SIZE; i++) {
		printf("%02x", sum_buff[i]);
	}
	printf(" %s\n", pass);
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        print_help();
        exit(0);
    }

    char line_buff[BUFFER_SIZE];

    FILE *pass_file = fopen(argv[1], "r");
    if(pass_file == NULL) {
        fprintf(stderr, "Error opening file: %s", argv[1]);
        exit(1);
    }

    while( fgets(line_buff, BUFFER_SIZE, pass_file) != NULL) {
        hash_line(line_buff);
    }

    fclose(pass_file);

    return 0;
}
