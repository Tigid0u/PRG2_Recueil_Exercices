#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define CLIGNOTEMENTS 100

void afficherGuirlande(unsigned char guirlande) {
    printf("\r");
    fflush(stdout);
    for (int i = 7; i >= 0; i--) {
        putchar((guirlande & (1 << i)) ? '*' : '_');
    }
}

int main() {
    unsigned char guirlande = 0b10101010;
    srand(time(NULL));
    afficherGuirlande(guirlande);
    for (int i = 0; i < CLIGNOTEMENTS; i++) {
        guirlande = ~guirlande;
        afficherGuirlande(guirlande);
        usleep(rand() % 1000000);
    }
    return 0;
}
