#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;

    printf("Meniu:\n");
    printf("1 - Creeaza fisier\n");
    printf("2 - Adauga data si ora in fisier\n");
    printf("3 - Afiseaza continutul fisierului\n");
    printf("4 - Iesire\n");
    printf("Introduceti optiunea: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 4) {
        return choice;  
    } else {
        printf("Optiune invalida.\n");
        return 0;
    }
}
