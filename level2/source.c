
void p(void) {
  // Adresse de retour stockée implicitement (utilisée plus tard pour vérification)
  unsigned int retaddr;

  // Buffer de 76 octets pour stocker l'entrée utilisateur
  char buffer[76];

  // Vide le buffer de sortie standard (stdout)
  fflush(stdout)

  // Lit l'entrée utilisateur sans vérification de taille → VULNÉRABLE !
  gets(buffer);

  // Simule une vérification de l'adresse de retour (emplacement où le programme sautera après p())
  // Ici, si l'adresse de retour commence par 0xb (donc dans la stack), il quitte brutalement
  if ((retaddr & 0xb0000000) == 0xb0000000) {
    printf("(%p)\n", retaddr);
    _exit(1);  // Termine immédiatement le programme
  }

  puts(buffer);
  strdup(buffer);

  return;
}



void main(void)

{
  p();
  return;
}
