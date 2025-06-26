int main(int argc, char **argv) {
    if (argc < 2) {
        exit(1);
    }
    
    N *obj1 = new N(5);        // Premier objet (108 bytes)
    N *obj2 = new N(6);        // Deuxième objet (108 bytes)
    
    obj1->setAnnotation(argv[1]);    // VULNÉRABILITÉ : buffer overflow
    
    // Appel de méthode virtuelle via vtable
    obj2->vtable[0](obj2, obj1);     // Équivalent de obj2->operator+(obj1)
    
    return 0;
}

/* N::N(int) */

void __thiscall N::N(N *this,int param_1)

{
  *(undefined ***)this = &PTR_operator+_08048848;
  *(int *)(this + 0x68) = param_1;
  return;
}


/* N::TEMPNAMEPLACEHOLDERVALUE(N&) */

int __thiscall N::operator+(N *this,N *param_1)

{
  return *(int *)(param_1 + 0x68) + *(int *)(this + 0x68);
}


/* N::TEMPNAMEPLACEHOLDERVALUE(N&) */

int __thiscall N::operator-(N *this,N *param_1)

{
  return *(int *)(this + 0x68) - *(int *)(param_1 + 0x68);
}


/* N::setAnnotation(char*) */

void __thiscall N::setAnnotation(N *this,char *param_1)

{
  size_t __n;
  
  __n = strlen(param_1);
  memcpy(this + 4,param_1,__n);
  return;
}

