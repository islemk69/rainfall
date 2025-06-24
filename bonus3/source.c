int main(int ac, char **av) {
    FILE *f;
    char buffer[132];  // 66 + 66 (flag + message)
    
    memset(buffer, 0, sizeof(buffer));
    f = fopen("/home/user/end/.pass", "r");

    if (!f || ac != 2) return -1;

    // Lire la première moitié du flag
    fread(buffer, 1, 66, f);

    // Mettre un \0 dans buffer[atoi(av[1])]
    buffer[atoi(av[1])] = '\0';

    // Lire le reste du fichier dans buffer + 66
    fread(buffer + 66, 1, 65, f);

    fclose(f);

    // Comparer buffer avec av[1]
    if (strcmp(buffer, av[1]) == 0) {
        execl("/bin/sh", "sh", NULL);
    } else {
        puts(buffer + 66);  // Affiche contenu de fin de .pass si erreur
    }

    return 0;
}