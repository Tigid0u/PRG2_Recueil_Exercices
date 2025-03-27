#include <stdio.h>

int main(){
    char tab[60];
    char* ptrs[3] = {tab+28, tab+18, tab+48};
    sprintf(ptrs[0], "%s", "lundi");
    sprintf(ptrs[1], "%s", "mardi");
    sprintf(ptrs[2], "%s", "mercredi");

    for(int i = 0; i < 3; i++){
        printf("%s\n", ptrs[i]);
    }
    return 0;
}