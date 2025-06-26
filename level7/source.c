#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Variable globale contenant le mot de passe
char c[68];

// Fonction appelée à la place de puts() après l'exploitation
void m(void *param_1, int param_2, char *param_3, int param_4, int param_5) {
    time_t t = time(NULL);
    printf("%s - %ld\n", c, t);
}

int main(int argc, char **argv) {
    void *structure1;
    void *buffer1;
    void *structure2;
    void *buffer2;
    FILE *fp;

    // Allocation de la première structure
    structure1 = malloc(8);
    *((int *)structure1) = 1;

    // Allocation du buffer pointé par structure1
    buffer1 = malloc(8);
    *((void **)(structure1 + 4)) = buffer1;

    // Allocation de la deuxième structure
    structure2 = malloc(8);       // contient un int + un pointeur vers buffer2
    *((int *)structure2) = 2;

    // Allocation du buffer pointé par structure2
    buffer2 = malloc(8);
    *((void **)(structure2 + 4)) = buffer2;

    strcpy(buffer1, argv[1]);

    // 🔥 Deuxième écriture vers buffer2 — mais le pointeur peut être corrompu
    strcpy(buffer2, argv[2]);

    // Lecture du mot de passe
    fp = fopen("/home/user/level8/.pass", "r");
    fgets(c, 68, fp);

    // Appel de puts — mais si la GOT est modifiée, on appelle m()
    puts("~~");

    return 0;
}
