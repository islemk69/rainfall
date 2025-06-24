int main(int ac, char **av) {
    FILE *f;
    char buffer[132];
    
    memset(buffer, 0, sizeof(buffer));
    f = fopen("/home/user/end/.pass", "r");

    if (!f || ac != 2) return -1;

    fread(buffer, 1, 66, f);

    buffer[atoi(av[1])] = '\0';

    fread(buffer + 66, 1, 65, f);

    fclose(f);

    if (strcmp(buffer, av[1]) == 0) {
        execl("/bin/sh", "sh", NULL);
    } else {
        puts(buffer + 66);  
    }

    return 0;
}