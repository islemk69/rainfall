
void main(void)

{
  n();
  return;
}


void n(void)

{
  char local_20c [520];
  
  fgets(local_20c,0x200,stdin);
  printf(local_20c);
  exit(1);
}


void o(void)

{
  system("/bin/sh");
  _exit(1);
}