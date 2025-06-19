#include <stdio.h>

int addition(int a, int b) {
    return a + b;
}

int soustraction(int a, int b) {
    return a - b;
}

int multiplication(int a, int b) {
    return a * b;
}

int division(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Erreur : division par zéro\n");
        return 0;
    }
}

int main() {
    int (*operations[4])(int, int) = { addition, soustraction, multiplication, division };
    int choice, a, b;

    printf("---- Operations ----\n");
    printf("1. Addition\n");
    printf("2. Substraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n\n");

    printf("Please choose an operation: ");
    while (!scanf("%d", &choice) || choice < 1 || choice > 4) {
        printf("Please enter a valid choice: ");
    }

    printf("Please enter the first integer: ");
    while (!scanf("%d", &a)) {
        printf("Please enter a valid number: ");
    }

    printf("Please enter the second integer: ");
    while (!scanf("%d", &b)) {
        printf("Please enter a valid number: ");
    }

    printf("\n\nResult = %d", operations[choice - 1](a, b));

    return 0;
}
