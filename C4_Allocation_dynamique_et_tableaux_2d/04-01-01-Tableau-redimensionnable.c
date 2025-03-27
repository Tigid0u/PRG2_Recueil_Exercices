#include <stdio.h>
#include <stdlib.h>

int main() {
    int *integers = malloc(5 * sizeof(int));
    int *prev = NULL;
    int i = 0;

    printf("Entrez un entier positif (une lettre pour finir):");
    while (scanf("%d", &integers[i++])) {
        if (i == sizeof(integers)) {
            prev = integers;
            integers = (int *)realloc(integers, 2 * sizeof(integers));
            if (!integers) {
                printf("Erreur d'allocation memoire !\n");
                free(prev);
                return 1;
            }
        }
        printf("Entrez un entier positif (une lettre pour finir):");
    }
    printf("Vous avez entre: ");
    for (int j = 0; j < i - 1; j++) {
        printf("%d ", integers[j]);
    }
    free(integers);
    return 0;
}
