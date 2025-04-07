#include <stdio.h>
#include <ctype.h>

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

int main(int argc, char *argv[]) {
    unsigned long long a, b, c;
    if (argc != 3) {
        printf("Usage: .\\conversion.exe [integer 1] [integer 2]\n");
        return 1;
    }
    if (!isInteger(argv[1]) || !isInteger(argv[2])) {
        printf("Arguments must be integers !\n");
        return 1;
    }


    return 0;
}
