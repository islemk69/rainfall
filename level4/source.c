#include <stdio.h>
#include <stdlib.h>

// Variable globale critique (non initialisée ici)
int m;

void p(char *user_input) {
    //Vulnérabilité : pas de format string dans printf()
    printf(user_input);
}

void n(void) {
    char buffer[520]; // 0x208

    // lecture de lentrée utilisateur (max 512 octets)
    fgets(buffer, 512, stdin);

    // Passage du buffer à la fonction vulnérable
    p(buffer);

    // Si la variable globale 'm' vaut exactement 0x1025544, on affiche le mot de passe
    if (m == 0x1025544) {
        system("/bin/cat /home/user/level5/.pass");
    }
}

int main(void) {
    n();
    return 0;
}
