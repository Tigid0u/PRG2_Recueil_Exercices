#include <stdio.h>
#include <stdlib.h>
#include "q4.h"

#define SEED_MAX 0x7FFFFFFF // Maximum value for the seed
#define LOW_BYTE_MASK 0xFF // Mask to get the low byte of the random number


// #ifdef DEBUG
// #define DBG_PRINTF(...) printf(__VA_ARGS__)
// #else
// #define DBG_PRINTF(...)
// #endif

static int myrand_state = 5669; // Internal state initialized with a constant
// value from https://en.wikipedia.org/wiki/List_of_prime_numbers

// Function to generate a pseudo-random number based on the seed
// and the internal state
int myrand(int seed) {

    // *** COMPLETER ***
    myrand_state *= seed;
    myrand_state = ((long long)myrand_state) % (SEED_MAX + 1LL);
    myrand_state &= LOW_BYTE_MASK;

    return myrand_state;
}

int main(int argc, char *argv[]) {
    const char *filepath = argv[1];
    int seed = atoi(argv[2]);
    int size = atoi(argv[3]);
    unsigned char buffer[BLOCK_SIZE];
    FILE *f = NULL;

    // The program expects the name of the output file, a seed, and a block size
    // as arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <output_file> <seed> <bloc size>\n", argv[0]);
        return 1;
    }

    // Check that the seed is a positive integer less than SEED_MAX
    if ((seed < 1) || (seed > SEED_MAX)) {
        // Check if the seed is a positive integer
        fprintf(stderr, "Invalid seed. Must be a positive integer > 1.\n");
        return 1;
    }

    // Check that the block size is a positive integer less than BLOCK_SIZE
    if (size <= 0 || size > BLOCK_SIZE) {
        fprintf(stderr, "Invalid block size. Must be between 1 and %d.\n", BLOCK_SIZE);
        return 1;
    }

    // Open the output file for writing

// *** COMPLETER ***
    f = fopen(filepath, "wb");
    if (f == NULL) goto cleanup;

    // Allocate a buffer for the block and fill it with random data

// *** COMPLETER ***
    size_t i;
    for (i = 0; i < BLOCK_SIZE; ++i) {
        unsigned char j = (unsigned char)myrand(seed);
        buffer[i] = j;
        //printf("%d\n", j);
    }

    // DEBUG: Print the generated block in a formatted way
    DBG_PRINTF("Generated block:\n");
    for (int i = 0; i < size; ++i) {
        if (i % 16 == 0) {
            DBG_PRINTF("buffer[%04d] = ", i);
            for (int j = 0; j < 16; j++) {
                if (i + j < size)
                    DBG_PRINTF("%02X ", buffer[i + j]);
            }
            DBG_PRINTF("\n");
        }
    }

    // Write the size of the block at the beginning of the file

// *** COMPLETER ***
    rewind(f);
    if (fwrite(&size, sizeof(int), 1, f) != 1) goto cleanup;

    // Write the block to the file

// *** COMPLETER ***
    if (fwrite(buffer, sizeof(unsigned char), BLOCK_SIZE, f) != BLOCK_SIZE) goto cleanup;

    // properly terminate the program

// *** COMPLETER ***
cleanup:
    fclose(f);

    return 0;
}
