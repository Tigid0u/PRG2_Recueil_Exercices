#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <inttypes.h>

#define DELIMITER '\''

int isInteger(char *str) {
    if (*str == '+' || *str == '-') {
        str++;
    }

    if (*str == '\0') {
        return 0;
    }

    while (isdigit(*str)) {
        str++;
    }

    return *str == '\0';
}

void insChar(char *str, size_t size, size_t index) {
    for (int i = size - 1; i > index; i--) {
        str[i] = str[i - 1];
    }
    str[index] = DELIMITER;
}

int main(int argc, char *argv[]) {
    int64_t a, b, res;
    size_t len, full_len, i;
    char *str = NULL, *full_str = NULL;
    int retval = 0, count;

    if (argc != 3) {
        printf("Usage: .\\conversion.exe [integer 1] [integer 2]\n");
        return 1;
    }
    if (!isInteger(argv[1]) || !isInteger(argv[2])) {
        printf("Arguments must be integers !\n");
        return 1;
    }

    a = strtoll(argv[1], NULL, 10);
    b = strtoll(argv[2], NULL, 10);

    res = a * b;

    if (a != 0 && res / a != b) {
        printf("%lld * %lld is too long !\n", a, b);
        retval = 1;
        goto cleanup;
    }

    len = snprintf(NULL, 0, "%lld", res);

    full_len = len + len / 3;

    printf("Sortie: [i] %llu characters needed to store %lld\n", full_len, res);

    str = (char *)malloc(full_len + 1);

    if (NULL == str) {
        printf("Bad alloc !\n");
        retval = 2;
        goto cleanup;
    }

    snprintf(str, full_len, "%lld", res);

    i = len - 1;
    count = 1;
    while (i > 0) {
        if (count % 3 == 0) {
            insChar(str, full_len, i);
            count = 0;
        }
        count++;
        i--;
    }

    printf("Sortie: [i] Result = %s", str);

cleanup:
    free(str);
    return retval;
}
