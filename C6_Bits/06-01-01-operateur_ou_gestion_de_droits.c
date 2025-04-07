#include <stdio.h>

int hasReadRights(unsigned char rights) {
    unsigned char mask = 0b00000001;
    return (rights & mask);
}

int hasWriteRights(unsigned char rights) {
    unsigned char mask = 0b00000010;
    return (rights & mask);
}

int main() {
    unsigned char rights = 0b00000000;
    unsigned char read = 0b000000001;
    unsigned char write = 0b00000010;

    //définir les droit avec `|=`
    rights |= read | write;

    if (rights & read) {
        printf("User has read rights !\n\n");
    }
    if (rights & write) {
        printf("User has write rights !\n\n");
    }
    return 0;
}
