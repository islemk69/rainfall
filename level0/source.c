
// undefined4 main(undefined4 param_1,int param_2)dfd
// {
//   int iVar1;
//   char *local_20;
//   undefined4 local_1c;
//   __uid_t local_18;
//   __gid_t local_14;
  
//   iVar1 = atoi(*(char **)(param_2 + 4));
//   if (iVar1 == 0x1a7) {
//     local_20 = strdup("/bin/sh");
//     local_1c = 0;d
//     local_14 = getegid();
//     local_18 = geteuid();
//     setresgid(local_14,local_14,local_14);
//     setresuid(local_18,local_18,local_18);
//     execv("/bin/sh",&local_20);
//   }
//   else {
//     fwrite("No !\n",1,5,(FILE *)stderr);
//   }
//   return 0;
// }


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

