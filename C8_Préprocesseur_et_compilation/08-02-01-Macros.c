#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Définition des macros */
#define CHIFFRE(c) (c >= 48 && c <= 57) ? 1 : 0

#define MINUSCULE(c) (c >= 97 && c <= 122) ? 1 : 0

#define MAJUSCULE(c) (c >= 65 && c <= 90) ? 1 : 0

#define MIN_MAJ(c) (MINUSCULE(c)) ? (c - 32) : c

#define MAJ_MIN(c) (MAJUSCULE(c)) ? (c + 32) : c

#define PERMUTE(a,b) { \
    int tmp = a; \
    a = b; \
    b = tmp; \
}

#define COPIE(s, t){ \
    for(size_t i = 0; i < sizeof(s); i++) t[i] = s[i]; \
}

/* A compléter */

int main() {

    char test_char = '5';
    char test_min_char = 'a';
    char test_maj_char = 'Z';
    int a = 10, b = 20;
    char lower_char = 't';
    char upper_char = 'K';
    char source[] = "Hello, world!";
    char destination[50];

    /* Teste si <test_char> est un chiffre */
    printf("Est-ce un chiffre ? %d\n", CHIFFRE(test_char));

    /* Teste si <test_min_char> est une minuscule */
    printf("Est-ce une minuscule ? %d\n", MINUSCULE(test_min_char));

    /* Teste si <test_maj_char> est une majuscule */
    printf("Est-ce une majuscule ? %d\n", MAJUSCULE(test_maj_char));

    /* Converti <lower_char> en majuscule SI minuscule */
    printf("En majuscule si minuscule : %c\n", MIN_MAJ(lower_char));

    /* Converti <upper_char> en minuscule SI majuscule */
    printf("En minuscule si majuscule : %c\n", MAJ_MIN(upper_char));

    printf("Avant permutation : a = %d, b = %d\n", a, b);

    /* A compléter */
    PERMUTE(a, b);

    printf("Après permutation : a = %d, b = %d\n", a, b);

    /* Effectue une copie de destination dans source avec la macro COPIE */

    /* A compléter */
    COPIE(source, destination);

    printf("Chaîne copiée : %s\n", destination);

    return 0;
}
