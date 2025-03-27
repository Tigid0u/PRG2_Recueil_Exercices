#include <stdio.h>

int main(){
    int nombre = 10;
    int* ptr = &nombre;

    printf("Nombre = %d", *ptr);
    return 0;
}