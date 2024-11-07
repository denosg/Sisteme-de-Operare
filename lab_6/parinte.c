#include <process.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct TEST_DATA
{
    char name[20];
    int n;
    double x;
} TEST_DATA;

char *envp[] = {"PARINTE=SPAWN FUNCTIONS", NULL};

void main(void)
{
    char *nargv[4];
    char buffer[20];
    char fname[40]; 
    TEST_DATA *pdata;
    if ((pdata = (TEST_DATA *)malloc(sizeof(TEST_DATA))) == NULL)
        abort();
    pdata->n = 100;
    pdata->x = 1000.99;
    strcpy(pdata->name, "PARINTE");
    nargv[0] = "fiu.exe";
    nargv[1] = fname;
    sprintf(buffer, "%Fp", (void *)pdata);
    printf("PARINTE : Lansare proces fiu : name = %s, n = %d, x = %f.\n", pdata->name, pdata->n, pdata->x);
    nargv[2] = buffer;
    nargv[3] = NULL;
    printf("Ce functie se apeleaza ?\n");
    scanf("%s",fname);
    strlwr(fname);
    if (strcmp(fname, "spawnl") == 0)
        spawnl(P_WAIT, "fiu.exe", "fiu.exe", fname, buffer, NULL);
    if (strcmp(fname, "spawnle") == 0)
        spawnle(P_WAIT, "fiu.exe", "fiu.exe", fname, buffer, NULL, envp);
    if (strcmp(fname, "spawnlp") == 0)
        spawnlp(P_WAIT, "fiu.exe", "fiu.exe", fname, buffer, NULL);
    if (strcmp(fname, "spawnlpe") == 0)
        spawnlpe(P_WAIT, "fiu.exe", "fiu.exe", fname, buffer, NULL, envp);
    if (strcmp(fname, "spawnv") == 0)
        spawnv(P_WAIT, "fiu.exe", nargv);
    if (strcmp(fname, "spawnve") == 0)
        spawnve(P_WAIT, "fiu.exe", nargv, envp);
    if (strcmp(fname, "spawnvp") == 0)
        spawnvp(P_WAIT, "fiu.exe", nargv);
    if (strcmp(fname, "spawnvpe") == 0)
        spawnvpe(P_WAIT, "fiu.exe", nargv, envp);
    if (strcmp(pdata->name, "PARINTE") == 0)
        printf("Se revine din procesul fiu : name = %s, n = %d, x = %f.\n", pdata->name, pdata->n, pdata->x);
    else
        printf("Eroare !\n");
}