#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t string_len(char *buf) {
    size_t i = 0;
    while (buf[i] != '\0') {
        i++;
    }
    return i - 1;
}

void string_copy(char *src, char *dest) {
    size_t len = string_len(src);
    memcpy(dest, src, len);
    dest[len] = '\0';
}

int main() {
    char buffer[200], *str = NULL;
    size_t length;
    int from, n, retval = 0;

    printf("Entrée: [?] Saisissez une ligne de mots: ");
    fgets(buffer, 200, stdin);

    length = string_len(buffer);

    str = (char *)malloc(length + 1);
    if (NULL == str) {
        printf("Bad alloc !\n");
        goto cleanup;
    }

    string_copy(buffer, str);

    printf("Sortie: [i] La ligne contient %zu caracteres\n", length);

    printf("Entrée: [?] Extraire APRES combien de caracteres? ");
    if (!scanf("%d", &from) || from < 0 || from >= length) {
        printf("Sortie: [!]Erreur: position impossible!\n");
        goto cleanup;
    }

    printf("Entrée: [?] Extraire combien de caracteres? ");
    if (!scanf("%d", &n) || n < 1 || from + n > length) {
        printf("Sortie: [!]Erreur: longueur impossible!\n");
        goto cleanup;
    }

    printf("Sortie: [i] La sous-chaine extraite de la chaine est : \"");
    for (int i = from; i < from + n; i++) {
        putchar(str[i]);
    }
    putchar('"');

cleanup:
    free(str);
    return retval;

    return 0;
}
