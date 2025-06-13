#include <stdio.h>
#include <stdlib.h>
#include "q2.h"

// Count the number of bits set to 1 in a byte
int count_bits(unsigned char byte) {
    int nb_bits = 0;
    // *** COMPLETER ***
    while (byte > 0) {
        if (byte % 2 != 0) {
            ++nb_bits;
        }
        byte /= (unsigned char)2;
    }
    return nb_bits;
}

int main(int argc, char *argv[]) {
    int size, total_bits = 0;
    FILE *f = NULL;
    unsigned char *buffer = NULL;
    size_t i;

    // The program expects the name of the binary file as an argument
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <binary_file>\n", argv[0]);
        return 1;
    }

    // Open the binary file for reading

// *** COMPLETER ***
    f = fopen(argv[1], "r");
    if (f == NULL) goto cleanup;


    // Read the header to get the size of the data block

// *** COMPLETER ***
    if (fread(&size, sizeof(int), 1, f) != 1) goto cleanup;

    // DEBUG: Print the size of the data block
    printf("Size of data block: %d bytes\n", size);

    // Allocate memory for the data block

// *** COMPLETER ***
    buffer = (unsigned char *)malloc(sizeof(unsigned char) * BLOCK_SIZE);
    if (buffer == NULL) goto lib_buffer;

    // Read the data block from the file

// *** COMPLETER ***
    if (fread(buffer, sizeof(unsigned char), size, f) != size) {
        printf("HEY\n");
        goto lib_buffer;
    }

    // Count the number of bits set to 1 in the block

// *** COMPLETER ***
    for (i = 0; i < BLOCK_SIZE; ++i) {
        total_bits += count_bits(buffer[i]);
    }

    // DEBUG: Print the generated block in a formatted way
    printf("Loaded block:\n");
    for (int i = 0; i < size; i++) {
        if (i % 16 == 0) {
            printf("buffer[%04d] = ", i);
            for (int j = 0; j < 16; j++) {
                if (i + j < size)
                    printf("%02X ", buffer[i + j]);
            }
            printf("\n");
        }
    }

    printf("Number of bits set to 1: %d\n", total_bits);


    // properly terminate the program

// *** COMPLETER ***
lib_buffer:
    free(buffer);
cleanup:
    fclose(f);

    return 0;
}
