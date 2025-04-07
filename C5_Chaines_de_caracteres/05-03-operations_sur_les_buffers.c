
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ask for a new word on stdin
// add the new word to the list
int moreTxt(char ***ptrList) {
    char word[100];
    static size_t index = 0;
    printf("[?] Ajouter un mot (STOP = '0'): ");
    scanf("%99s", word);
    if (word[0] == '0') return 0; //terminate if '0' is typed;
    if (*ptrList == NULL) {
        *ptrList = (char **)calloc(1, sizeof(char *));
    } else {
        *ptrList = (char **)realloc(*ptrList, (index + 1) * sizeof(char *));
        index++;
    }
    if (!*ptrList) {
        printf("[!] Erreur d'allocation memoire pour la liste de mots !\n");
        return 0;
    }
    *ptrList[index] = (char *)malloc(strlen(word)); //Char is 1 byte
    strcpy(*ptrList[index], word);
    return 1;
}

// build a string (a phrase) from a list of words
// Words are appended, separated by a white space
int makePhrase(char **ptrPhrase, char **list) {
    // **********************
    // *** your code here ***
    // **********************
}

int main(void) {
    char **list = NULL;    // <-- list of words
    char *phrase = NULL;   // <-- resulting "phrase"
    int count = 0;         // <-- number of words in list

    // reading words
    while (moreTxt(&list)) ++count;
    printf("[i] La liste finale contient %d mots\n", count);

    // making phrase
    if (count > 0) {
        if (makePhrase(&phrase, list))
            printf("[i] Ce qui donne la phrase \"%s\"\n", phrase);
    }

    return 0;
}
