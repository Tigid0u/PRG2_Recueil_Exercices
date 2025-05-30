#include <stdbool.h>
#include <stdio.h>

// Une certaine configuration 

#define CONFIG_VERSION 23

#define CONFIG_STACK_PROTECTION

#define CONFIG_OS_WIN     
// #define CONFIG_OS_LINUX     


// La structure doit avoir tous les membres alignés sur 16 octets
#pragma pack(push, 16)
typedef struct {

    // Le champ suivant, uniquement pour une config WIN avec la version étant égale à 23
    // Les conditions doivent être exprimées en une seule ligne
#if  defined(CONFIG_OS_WIN) && (CONFIG_VERSION == 23)
    unsigned int addr;
#elif defined(CONFIG_OS_LINUX)
    // Et celui-ci, uniquement pour une config Linux
    unsigned long addrl;
#else
    // Si ni Linux, ni WIN, afficher une erreur de compilation.
#error Bad config !
#endif
// Autres champs présents dans tous les cas
    unsigned long size;
    bool valid;
} mem_desc_t;
#pragma pack(pop)

// Uniquement si CONFIG_STACK_PROTECTION
#ifdef CONFIG_STACK_PROTECTION
void stack_validate(void) {
    printf("Stack validation\n");
}
#endif

int main() {

    /* ... */

    printf("Size of mem_desc: %lu\n", sizeof(mem_desc_t));

#ifdef CONFIG_STACK_PROTECTION
    stack_validate();
#endif
    /* ... */
}
