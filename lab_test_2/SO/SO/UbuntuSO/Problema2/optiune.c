#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;

    printf("Meniu:\n");
    printf("1 - Creeaza fisier\n");
    printf("2 - Sorteaza fisierul\n");
    printf("3 - Afiseaza continutul fisierului\n");
    printf("0 - Iesire\n");
    printf("Introduceti optiunea: ");
    scanf("%d", &choice); 
    if (choice >= 0 && choice <= 3) {
        return choice; 
    } else {
        printf("Optiune invalida.\n");
        return -1; 
    }
}
