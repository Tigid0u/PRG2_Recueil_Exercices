#ifndef TEB_BLOCK_H
#define TEB_BLOCK_H

#include <stdio.h>

#define BLOCK_SIZE 4096  // Max size of the block to generate
#define DEBUG 1

// Ne jamais définir DEBUG ici — c’est fait via -DDEBUG=0 ou -DDEBUG=1 lors de la compilation

#if defined(DEBUG) && DEBUG == 1

// DEBUG == 1 → printf avec numéro de ligne sauf si format commence par '\n'
#define DBG_PRINTF(fmt, ...) \
    do { \
        if ((fmt)[0] == '\n') \
            printf(fmt, ##__VA_ARGS__); \
        else { \
            printf("(%d) ", __LINE__); \
            printf(fmt, ##__VA_ARGS__); \
        } \
    } while (0)

#elif defined(DEBUG) && DEBUG == 0

// DEBUG == 0 → printf normal
#define DBG_PRINTF(fmt, ...) \
    do { \
        printf(fmt, ##__VA_ARGS__); \
    } while (0)

#else

// DEBUG non défini → pas de trace
#define DBG_PRINTF(...) do {} while (0)

#endif

#endif // TEB_BLOCK_H
