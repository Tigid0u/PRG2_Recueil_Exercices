#include <stdio.h>
#include <stdlib.h>

enum couleur_e { COEUR, CARREAU, PIQUE, TREFLE };
enum valeur_e { SEPT, HUIT, NEUF, DIX, VALET, DAME, ROI, AS };

struct carte {
    enum couleur_e couleur;
    enum valeur_e valeur;
};

struct jeu {
    struct carte cartes[32];
    int nb_cartes;
};

const char *chaines_couleur[4] = { "Coeur", "Carreau", "Pique", "Trefle" };
const char *chaines_valeur[8] = { "7", "8", "9", "10", "Valet", "Dame", "Roi", "As" };

// Fonction pour générer un nombre "pseudo-aléatoire" prédictible
static int myrand = 5669; // état interne = valeur de départ
int myrand_func() {
    myrand *= myrand;
    return myrand & 0xFF;
}

// Remplit un jeu complet de 32 cartes
void jeu_de_cartes(struct jeu *j) {

    // *** COMPLETER ***
    size_t i, k, index;

    j->nb_cartes = 32;
    for (i = 0; i < 4; ++i) {
        for (k = 0; k < 8; ++k) {
            index = i * 8 + k;
            j->cartes[index].couleur = i;
            j->cartes[index].valeur = k;
        }
    }
}

// Affiche les cartes d'un jeu
void affiche_jeu(const struct jeu *j) {

    // *** COMPLETER ***
    size_t i;

    for (i = 0; i < j->nb_cartes; ++i) {
        printf("%s de %s\n", chaines_valeur[j->cartes[i].valeur], chaines_couleur[j->cartes[i].couleur]);
    }
}

// Mélange le jeu de cartes
void melange_jeu(struct jeu *j) {
    // algorithme de mélange de Fisher-Yates
    // on prend la dernière carte du tas et on l'échange avec une carte aléatoire
    // puis on recommence sans la nouvelle dernière carte qui reste à sa position

// *** COMPLETER ***
    size_t i, k;
    struct carte buff;
    for (i = j->nb_cartes; i > 0; --i) {
        k = myrand_func() % (size_t)i;
        buff = j->cartes[i - 1];
        j->cartes[i - 1] = j->cartes[k];
        j->cartes[k] = buff;
    }
}

// Distribue les cartes aux joueurs
struct jeu *donne(int joueurs, const struct jeu *j) {

    // *** COMPLETER ***
    struct jeu *mains = NULL;
    size_t i, k, index;
    size_t nb_cartes_par_joueurs = j->nb_cartes / joueurs;

    mains = (struct jeu *)malloc(sizeof(struct jeu) * joueurs);
    if (mains == NULL) goto cleanup;
    for (i = 0; i < joueurs; ++i) {
        mains[i].nb_cartes = nb_cartes_par_joueurs;
        for (k = 0; k < nb_cartes_par_joueurs; ++k) {
            index = i * nb_cartes_par_joueurs + k;
            mains[i].cartes[k] = j->cartes[index];
        }
    }
    return mains;

cleanup:
    free(mains);
    return NULL;
}

int main() {
    int joueurs;
    printf("Entrez le nombre de joueurs (1-8): ");
    scanf("%d", &joueurs);
    if (joueurs < 1 || joueurs > 8) {
        printf("Nombre de joueurs invalide. (1 à 8)\n");
        return 1;
    }

    struct jeu j;
    jeu_de_cartes(&j);
    melange_jeu(&j);

    struct jeu *mains = donne(joueurs, &j);
    for (int p = 0; p < joueurs; p++) {
        printf("\nMain du joueur %d:\n", p + 1);
        affiche_jeu(&mains[p]);
    }

    free(mains);

    return 0;
}
