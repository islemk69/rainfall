// ============================================================================
// BONUS1
// ============================================================================

int main(int argc, char **argv)
{
  char buffer[40];
  int number;
  

  number = atoi(argv[1]);
  

  if (number < 10) {
    
    memcpy(buffer, argv[2], number * 4);
    
    // 0x574f4c46 = "FLOW" en little-endian
    if (number == 0x574f4c46) {
      execl("/bin/sh", "sh", 0);
    }
    
    return 0;
  }
  else {
    return 1;
  }
}