#include <stdio.h>
#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

void dump(const char *fisier, char format);
void info(const char *fisier, char *atrib, long *lg);
void parinte(const char *fisier, char *par);

#endif

int main() {
    char atribut[50];
    long lungime;
    char parinte_dir[256];

    // Afi?area con?inutului fi?ierului �n format caracter
    printf("Con?inutul fi?ierului �n format caracter:\n");
    dump("exemplu.txt", 'C');

    // Afi?area con?inutului fi?ierului �n format hexazecimal
    printf("\nCon?inutul fi?ierului �n format hexazecimal:\n");
    dump("exemplu.txt", 'X');

    // Ob?inerea informa?iilor despre fi?ier
    info("exemplu.txt", atribut, &lungime);
    printf("\nAtribut: %s, Lungime: %ld bytes\n", atribut, lungime);

    // Determinarea directorului parinte al fi?ierului
    parinte("exemplu.txt", parinte_dir);  // Acum folosim `parinte_dir`
    printf("Directorul părinte: %s\n", parinte_dir);

    return 0;
}
