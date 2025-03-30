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
    int openingCount = 0, closingCount = 0;
    for (size_t i = 0; i < size; i++) {
        if (str[i] == '(') openingCount++;
        else if (str[i] == ')') closingCount++;
        else if (str[i] == '\0') break;
    }
    return !(openingCount == closingCount);
}

int main() {
    char line[100];

    printf("[?] Saisissez une ligne de mots et parentheses (max %d carac.): ", 99);
    if (lire_ligne(line, 100)) printf("Oups, erreur ! !\n");
    if (missingParenthesis(line, 100)) printf("Il manque des parentheses :(\n");
    return 0;
}
