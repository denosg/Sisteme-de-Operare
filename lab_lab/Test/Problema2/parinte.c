#include <stdio.h>
#include <stdlib.h>
#include <process.h>  // Pentru spawnl

// Definirea unei structuri de date pentru a fi partajata Œntre procese
struct Data {
    int valoare1;
    int valoare2;
};

int main() {
    struct Data date_comune = {10, 20};  // Valori ini?iale pentru structura de date

    // Pregatim parametrii pentru procesul fiu
    char *param1 = (char *)malloc(sizeof(char) * 10);  // Alocam memorie pentru parametrii
    sprintf(param1, "%d", date_comune.valoare1);       // Convertim valoarea1 Œn string
    char *param2 = (char *)malloc(sizeof(char) * 10);
    sprintf(param2, "%d", date_comune.valoare2);       // Convertim valoarea2 Œn string

    // Lansam procesul fiu
    int pid = spawnl(P_WAIT, "FIU.EXE", "FIU.EXE", param1, param2, NULL);

    if (pid == -1) {
        perror("Eroare la lansarea procesului fiu");
        exit(1);
    }

    // A?teptam terminarea procesului fiu ?i apoi afisam datele prelucrate
    printf("Datele prelucrate de procesul fiu:\n");
    printf("Valoare 1 prelucrata: %d\n", date_comune.valoare1);
    printf("Valoare 2 prelucrata: %d\n", date_comune.valoare2);

    // Eliberam memoria alocata
    free(param1);
    free(param2);

    return 0;
}
