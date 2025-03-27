#include <stdio.h>

void sum(int *a, int *b, int *res, size_t size) {
    for (int i = 0; i < size; i++) {
        res[i] = a[i] + b[i];
    }
}

void displayTab(const int *tab, size_t size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        if (i) printf(", ");
        printf("%d", tab[i]);
    }
    printf("]");
}

int main() {
    int a[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
    int b[20] = { 21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40 };
    int c[20];

    //Compute sum
    sum(a, b, c, 20);

    //Display results
    printf("Results:\n\n");
    printf("a = ");
    displayTab(a, 20);
    printf("\nb = ");
    displayTab(b, 20);
    printf("\nc = ");
    displayTab(c, 20);

    return 0;
}
