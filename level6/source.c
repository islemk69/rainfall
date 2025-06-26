void main(undefined4 param_1, int param_2) {
    char *__dest;
    undefined4 *puVar1;
    
    __dest = (char *)malloc(0x40);    // Allocation de 64 bytes
    puVar1 = (undefined4 *)malloc(4);  // Allocation de 4 bytes
    *puVar1 = m;                      // Stockage de l'adresse de la fonction m
    strcpy(__dest, *(char **)(param_2 + 4));  // Copie de l'argument sans vérification
    (*(code *)*puVar1)();             // Appel de la fonction pointée
    return;
}