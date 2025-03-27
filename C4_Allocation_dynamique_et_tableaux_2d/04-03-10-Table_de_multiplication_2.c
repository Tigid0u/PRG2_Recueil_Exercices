#include <stdio.h>
#include <stdlib.h>

void display2dTab(int **tab, size_t lines, size_t cols) {
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%2d ", tab[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int **tab2d = NULL;
    int *tab1d = NULL;

    int lines, cols;

    printf("Entrez le nombre de lignes:");
    while (!scanf("%d", &lines) || lines < 0) {
        printf("Erreur de saisie. Entrez un entier positif :");
        while (getchar() != '\n');
    }

    printf("Entrez le nombre de colonnes:");
    while (!scanf("%d", &cols) || cols < 0) {
        printf("Erreur de saisie. Entrez un entier positif :");
        while (getchar() != '\n');
    }

    tab2d = (int **)calloc(lines, sizeof(int *));

    if (!tab2d) {
        printf("Memory alloc error tab2d !\n");
        goto free_mem;
    }

    for (int i = 1; i <= lines; i++) {
        tab1d = (int *)malloc(cols * sizeof(int));
        if (!tab1d) {
            printf("Memory alloc error tab1d !\n");
            goto free_mem;
        }
        for (int j = 1; j <= cols; j++) {
            tab1d[j - 1] = i * j;
        }
        tab2d[i - 1] = tab1d;
    }

    display2dTab(tab2d, lines, cols);

free_mem:
    for (int i = 0; i < (sizeof(tab2d) / sizeof(tab2d[0])); i++) {
        free(tab2d[i]);
    }
    free(tab2d);
    return 0;
}
