#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char **argv) {
    int input;
    char *cmd;
    uid_t uid;
    gid_t gid;

    // Conversion de l'argument en entier
    input = atoi(argv[1]);

    if (input == 423) { // 0x1a7 en hexadécimal
        cmd = strdup("/bin/sh");
        gid = getegid();
        uid = geteuid();

        setresgid(gid, gid, gid);
        setresuid(uid, uid, uid);

        execv("/bin/sh", &cmd);
    } else {
        fwrite("No !\n", 1, 5, stderr);
    }

    return 0;
}

