// ============================================================================
// FONCTION MAIN
// ============================================================================
undefined4 main(void)
{
  char local_3a[54];
  
  pp(local_3a);
  puts(local_3a);
  return 0;
}

// ============================================================================
// FONCTION PP
// ============================================================================
void pp(char *param_1)
{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  byte bVar4;
  char local_34[20];
  char local_20[20];
  
  bVar4 = 0;
  
  p(local_34, &DAT_080486a0);
  p(local_20, &DAT_080486a0);
  
  strcpy(param_1, local_34);
  
  // Calcul de la longueur de param_1 (équivalent à strlen)
  uVar2 = 0xffffffff;
  pcVar3 = param_1;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + (uint)bVar4 * -2 + 1;
  } while (cVar1 != '\0');
  
  // Ajout d'un espace à la fin de param_1
  (param_1 + (~uVar2 - 1))[0] = ' ';
  (param_1 + (~uVar2 - 1))[1] = '\0';
  
  // Concaténation du deuxième input
  strcat(param_1, local_20);
  
  return;
}

// ============================================================================
// FONCTION P
// ============================================================================
void p(char *param_1, char *param_2)
{
  char *pcVar1;
  char local_100c[4104];
  

  puts(param_2);
  
  read(0, local_100c, 0x1000);
  
  // Recherche du caractère newline ('\n')
  pcVar1 = strchr(local_100c, 10);
  
  // Remplacement du newline par '\0'
  *pcVar1 = '\0';  // ← SEGFAULT si pcVar1 == NULL !
  
  // Copie de maximum 20 bytes vers la destination
  strncpy(param_1, local_100c, 0x14);
  
  return;
}