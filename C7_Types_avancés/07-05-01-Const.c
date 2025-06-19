#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_substr_in_str(const char *str, const char *substr) {
    return strstr(str, substr) != NULL;
}


int main() {
    const char *find = "subcmd";
    const char *chaines[4] = {
        "commande1 subcmd",
        "autre commande",
        "encore subcmd ici",
        "dernière chaîne"
    };

    for (int i = 0; i < 4; i++) {
        if (is_substr_in_str(chaines[i], find)) {
            printf("\"%s\" found in the array at %d\n", find, i);
            return 0;
        }
    }

    printf("\"%s\" not found in the array !\n");

    return 0;
}
