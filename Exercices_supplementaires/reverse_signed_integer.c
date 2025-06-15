#include <stdio.h>
#include <stdlib.h>

int main() {
    int orginal, i = 0, j = 0;
    size_t nb_chars_needed;

    char *str = NULL, *reverse;

    printf("Original integer: ");

    while (scanf("%d", &orginal) == 0) {
        printf("Invalid input ! Please enter a valid input: ");
    }

    nb_chars_needed = snprintf(NULL, 0, "%d", orginal);

    str = (char *)malloc(nb_chars_needed + 1);
    reverse = (char *)malloc(nb_chars_needed + 1);

    if (NULL == str || NULL == reverse) {
        printf("Memory allocation error !\n");
        free(str);
        free(reverse);
        return 1;
    }

    snprintf(str, nb_chars_needed + 1, "%d", orginal);

    j = nb_chars_needed - 1;
    while (i < nb_chars_needed && j >= 0) {
        reverse[i++] = str[j--];
    }
    reverse[nb_chars_needed] = '\0';

    printf("Reversed integer: %s", reverse);

    free(str);
    free(reverse);

    return 0;
}
