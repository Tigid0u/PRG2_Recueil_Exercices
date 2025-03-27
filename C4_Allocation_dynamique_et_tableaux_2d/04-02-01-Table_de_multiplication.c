#include <stdio.h>
#include <stdlib.h>

#define WIDTH 7
#define HEIGHT 6

void display2dTab(int **tab) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%2d ", tab[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int **tab2d = NULL;
    int *tab1d = NULL;

    tab2d = (int **)calloc(WIDTH, sizeof(int *));

    if (!tab2d) {
        printf("Memory alloc error tab2d !\n");
        goto free_mem;
    }

    for (int i = 1; i <= HEIGHT; i++) {
        tab1d = (int *)calloc(HEIGHT, sizeof(int));
        if (!tab1d) {
            printf("Memory alloc error tab1d !\n");
            goto free_mem;
        }
        for (int j = 1; j <= WIDTH; j++) {
            tab1d[j - 1] = i * j;
        }
        tab2d[i - 1] = tab1d;
    }

    display2dTab(tab2d);

free_mem:
    for (int i = 0; i < (sizeof(tab2d) / sizeof(tab2d[0])); i++) {
        free(tab2d[i]);
    }
    free(tab2d);
    return 0;
}
