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

// Constructeur de la classe N
void N::N(N *this, int param_1) {
    this->vtable = &N_vtable;     // Pointeur vtable à l'offset +0
    this->value = param_1;        // Valeur (5 ou 6) à l'offset +0x68
}

// Fonction vulnérable
void N::setAnnotation(N *this, char *param_1) {
    size_t len = strlen(param_1);
    memcpy(this + 4, param_1, len);  // Copie SANS vérification de taille !
}