#include <stdio.h>

int lire_ligne(char *buffer, size_t size) {
    char tmp;
    int i = 0;
    while ((tmp = getchar()) != '\n') {
        if (i >= size - 1) {
            buffer[i] = '\0';
            return 1;
        }
        buffer[i++] = tmp;
    }
    buffer[i] = '\0';
    return 0;
}

int missingParenthesis(char *str, size_t size) {
    for (size_t i = 0; i < size; i++) {
        //TODO
    }
}

int main() {
    char line[100];

    printf("Type some text (max %d chararcters): ", 99);
    if (lire_ligne(line, 100)) printf("Something went wrong !\n");
    printf("You typed:\n\"%s\"", line);

    return 0;
}
