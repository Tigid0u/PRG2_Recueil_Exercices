#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define CLIGNOTEMENTS 100

void afficherGuirlande(unsigned char guirlande) {
    printf("\r");
    fflush(stdout);
    for (int i = 0; i < 8; i++) {
        putchar(((1 << i) & guirlande) ? '*' : '-');
    }
}

int main() {
    srand(time(NULL));
    unsigned char guirlande = 0b10101010;
    for (int i = 0; i < CLIGNOTEMENTS; i++) {
        afficherGuirlande(guirlande);
        guirlande = ~guirlande;
        usleep(rand() % 500000);
    }
}
