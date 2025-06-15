#include <stdio.h>

#define NB_NUMS 5

int main() {
    const int numbers[NB_NUMS] = { 1, 5, 4, 3, 6 };
    int val;

    printf("Indices of the two numbers whose sum equal to target value: ");
    while (scanf("%d", &val) == 0) {
        printf("Invalid input ! Please enter a valid input: ");
    }

    for (int i = 0; i < NB_NUMS; i++) {
        for (int j = 0; j < NB_NUMS; j++) {
            if (j != i && numbers[i] + numbers[j] == val) {
                printf("Indices: %d %d\n", i, j);
                return 0;
            }
        }
    }
    printf("No pair of indices matches the value %d\n", val);

    return 0;
}
