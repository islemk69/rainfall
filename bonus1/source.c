// ============================================================================
// BONUS1 - VERSION LISIBLE
// ============================================================================

int main(int argc, char **argv)
{
  char buffer[40];           // Buffer de 40 bytes
  int number;                // Nombre converti depuis argv[1]
  
  // Conversion du premier argument en entier
  number = atoi(argv[1]);
  
  // Vérification : le nombre doit être < 10
  if (number < 10) {
    
    // Copie argv[2] dans buffer
    // Taille copiée = number * 4 bytes
    memcpy(buffer, argv[2], number * 4);
    
    // Vérification magique : si number == 0x574f4c46 ("FLOW" en little-endian)
    if (number == 0x574f4c46) {
      execl("/bin/sh", "sh", 0);  // Lance un shell !
    }
    
    return 0;  // Succès
  }
  else {
    return 1;  // Erreur : nombre trop grand
  }
}