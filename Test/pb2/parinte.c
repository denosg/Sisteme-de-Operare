#include <stdio.h>
#include <stdlib.h>
#include <process.h>

struct Data {
    int val1;
    int val2;
};

int main() {
    struct Data commonData = {15, 30};
    char *param1 = (char *)malloc(sizeof(char) * 10);
    char *param2 = (char *)malloc(sizeof(char) * 10);
    char *output_file = "output.txt";

    printf("Data from parinte.exe:\n");
    printf("Val 1: %d\n", commonData.val1);
    printf("Val 2: %d\n", commonData.val2);

    sprintf(param1, "%d", commonData.val1);
    sprintf(param2, "%d", commonData.val2);

    int pIdx = spawnl(P_WAIT, "fiu.exe", "fiu.exe", param1, param2, output_file, NULL);

    if (pIdx == -1) {
        perror("Error launchig fiu.exe because pIdx is -1");
        exit(1);
    }

    FILE *file = fopen(output_file, "r");
    if (file == NULL) {
        perror("Error launchig fiu.exe because file is null");
        exit(1);
    }
    fscanf(file, "%d\n%d\n", &commonData.val1, &commonData.val2);
    fclose(file);

    printf("Data configured by fiu.exe:\n");
    printf("Val 1: %d\n", commonData.val1);
    printf("Val 2: %d\n", commonData.val2);

    free(param1);
    free(param2);

    return 0;
}
