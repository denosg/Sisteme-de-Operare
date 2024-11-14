#include <stdio.h>
#include <stdlib.h>

void configureData(int *val1, int *val2) {
    *val1 += 7;
    *val2 *= 9;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Invalide numbers of parameters\n");
        exit(1);
    }

    int val1 = atoi(argv[1]);
    int val2 = atoi(argv[2]);
    char *output_file = argv[3];

    configureData(&val1, &val2);

    printf("Data to parinte.exe:\n");
    printf("Val 1: %d\n", *(&val1));
    printf("Val 2: %d\n", *(&val2));

    FILE *file = fopen(output_file, "w");
    if (file == NULL) {
        perror("Error opening destination file");
        exit(1);
    }
    fprintf(file, "%d\n%d\n", val1, val2);
    fclose(file);

    exit(0);
}
