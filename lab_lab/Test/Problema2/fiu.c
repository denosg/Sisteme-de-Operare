#include <stdio.h>
#include <stdlib.h>

// Func?ia care prelucreaza datele
void prelucreaza_date(int *valoare1, int *valoare2) {
    // De exemplu, vom adauga 5 la valoarea1 ?i vom Œnmul?i valoarea2 cu 2
    *valoare1 += 5;
    *valoare2 *= 2;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Numar invalid de parametri\n");
        exit(1);
    }

    // Convertim parametrii primi?i Œn valori Œntregi
    int valoare1 = atoi(argv[1]);
    int valoare2 = atoi(argv[2]);

    // Prelucram datele
    prelucreaza_date(&valoare1, &valoare2);

    // Afi?am datele prelucrate
    printf("Date prelucrate Œn procesul fiu:\n");
    printf("Valoare 1 prelucrata: %d\n", valoare1);
    printf("Valoare 2 prelucrata: %d\n", valoare2);

    // Redam controlul procesului parinte
    exit(0);
}
