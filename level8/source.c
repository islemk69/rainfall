#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *auth = NULL;
char *service = NULL;

int main(void) {
    char buffer[128];

    while (1) {
        printf("%p, %p\n", auth, service);

        if (!fgets(buffer, sizeof(buffer), stdin)) {
            return 0;
        }

        if (strncmp(buffer, "auth ", 5) == 0) {
            auth = (char *)malloc(4);
            if (!auth) exit(1);
            memset(auth, 0, 4);

            if (strlen(buffer + 5) < 31) {
                strcpy(auth, buffer + 5);
            }
        }

        if (strncmp(buffer, "reset", 5) == 0) {
            free(auth);
        }

        if (strncmp(buffer, "service", 7) == 0) {
            service = strdup(buffer + 7);
        }

        if (strncmp(buffer, "login", 5) == 0) {
            if (auth && *(int *)(auth + 32) != 0) {
                system("/bin/sh");
            } else {
                fwrite("Password:\n", 1, 10, stdout);
            }
        }
    }
}