#include <stdio.h>
#include <stdlib.h>

int m;  // Variable globale (non initialisée)

void v(void) {
    char buffer[520];  // = 0x208 = 520 octets

    // Lecture sécurisée (en apparence) de max 512 octets depuis l'entrée standard
    fgets(buffer, 512, stdin);

    // VULNÉRABILITÉ : printf est appelé directement avec un buffer contrôlé par l'utilisateur
    // Si le buffer contient un format string comme "%x" ou "%n", il sera interprété.
    printf(buffer);

    // Si la valeur de m est exactement 0x40 (64 en décimal), on spawn un shell
    if (m == 0x40) {
        fwrite("Wait what?!\n", 1, 12, stdout);
        system("/bin/sh");
    }
}

int main(void) {
    v();
    return 0;
}
