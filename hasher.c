#include <stdio.h>
#include <stdlib.h>

// For hashing function
#include <openssl/evp.h>

// Buffer size for storing lines
#define BUFFER_SIZE 256
// Size of the resulting sum or digest after hashing
#define SUM_SIZE 20

// Number of iterations for the PBKDF2 hashing function
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

// Function that implements the hashing of a single line.
// pass should be a buffer containing a single NULL terminated password to hash.
// In case a line contains a newlie, it will be truncated at that point with a NULL terminator.
void hash_line(char *pass) {
	// Make sure the line is NULL terminated
    null_terminate_newline(pass);

	unsigned char sum_buff[SUM_SIZE];

	// Execute the hash and store it in sum_buff
	PKCS5_PBKDF2_HMAC(pass, -1,
			NULL, 0, ITER_COUNT,
			EVP_sha1(),
			SUM_SIZE, sum_buff);

	// Print the sum
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

	// Open the file containing the "passwords" to hash
    FILE *pass_file = fopen(argv[1], "r");
    if(pass_file == NULL) {
        fprintf(stderr, "Error opening file: %s", argv[1]);
        exit(1);
    }

	// Line by line, print the passwords
    while( fgets(line_buff, BUFFER_SIZE, pass_file) != NULL) {
		// Hash the current password
        hash_line(line_buff);
    }

	// Close the file at the end
    fclose(pass_file);

    return 0;
}
