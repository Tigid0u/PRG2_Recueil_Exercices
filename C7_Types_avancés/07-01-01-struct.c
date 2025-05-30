#include <stdio.h>

#define TAILLE_INVENTAIRE 10

typedef struct {
    char titre[100];
    char autheur[100];
    int annee;
    int nb_copies;
}livre;

int ajouterLivre(livre *inventaire, size_t *taille) {
    livre l;
    if (*taille >= TAILLE_INVENTAIRE) return 1;
    printf("Titre:");
    scanf("%99s", l.titre);
    printf("Autheur:");
    scanf("%99s", l.autheur);
    printf("Annee:");
    scanf("%d", &l.annee);
    printf("Nombre de copies:");
    scanf("%d", &l.nb_copies);

    inventaire[*taille] = l;
    taille++;
    return 0;
}



int main() {
    livre inventaire[TAILLE_INVENTAIRE];
    livre l1 = { "Les schtroumpfs", "Gargamel", 2003, 200 };
    size_t taille = 0;

    inventaire[0] = l1;
    taille++;

    printf("Inventaire: \n\n");

    printf("Taille de l'inventaire:\t%d\n\n", taille);

    for (size_t i = 0; i < taille; i++) {
        printf("-------- Livre %d --------\n", i + 1);
        printf("%s:\t\t %s\n", "Titre", inventaire[i].titre);
        printf("%s:\t %s\n", "Autheur", inventaire[i].autheur);
        printf("%s:\t\t %d\n", "Annee", inventaire[i].annee);
        printf("%s:\t %d\n\n", "Nb copies", inventaire[i].nb_copies);
    }

    return 0;
}
