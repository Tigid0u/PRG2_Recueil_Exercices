#include <stdio.h>
#include <string.h>

int main(){
    char nom[30];
    int age;
    int* ptr_age = &age;
    char* ptr_nom = nom;
    char** ptr_ptr_nom = &ptr_nom;
    int** ptr_ptr_age = &ptr_age;
    **ptr_ptr_age = 21;
    strcpy(*ptr_ptr_nom, "Nolan");

    printf("Nom: %s, Age: %d", nom, age);
    return 0;
}