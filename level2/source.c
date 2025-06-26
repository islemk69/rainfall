
void p(void) {
  unsigned int retaddr;
  char buffer[76];

  fflush(stdout)

  // Lit l'entrée utilisateur sans vérification de taille → VULNÉRABLE !
  gets(buffer);

  // Simule une vérification de l'adresse de retour (emplacement où le programme sautera après p())
  // Ici, si l'adresse de retour commence par 0xb (donc dans la stack), il quitte brutalement
  if ((retaddr & 0xb0000000) == 0xb0000000) {
    printf("(%p)\n", retaddr);
    _exit(1);  
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
