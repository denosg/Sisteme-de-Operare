#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;

    printf("meniu:\n");
    printf("1. creeaza fisier\n");
    printf("2. adauga data in fisier\n");
    printf("3. afiseaza ce este in fisier\n");
    printf("4. iesire\n");
    printf("enter option: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 4) {
        return choice;  
    } else {
        printf("nu merge.\n");
        return 0;
    }
}
