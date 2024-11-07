#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dos.h>

typedef struct TEST_DATA
{
    char name[20];
    int n;
    double x;
} TEST_DATA;

void *p_s1;
void *p_s2;
char *myname = "FIU";

void main(int argc, char **argv, char **envp)
{
    char **p_t;
    TEST_DATA *pdata;
    printf("FIU : am primit % d argumente.\n", argc);
    if (argc < 3)
    {
        printf("Nu sunt suficiente !\n");
        exit(1);
    }
    void *ps1;
    void *ps2;
    printf("FIU a fost apelat prin % s.\n", argv[1]);
    printf("FIU : ambianta contine :\n");
    /* se tiparesc sirurile de ambianta */
    for (p_t = envp; *p_t != NULL; p_t++)
        printf("% s\n", *p_t);
    /* urmeaza conversia inversa, a sirului de caractere */
    sscanf(argv[2], "% Fp", (void *)&pdata);
    printf("In FIU : name = % Fs, n = % d, x = % f.\n",
           pdata->name, pdata->n, pdata->x);
    ps1 = (void *)myname;
    ps2 = (void *)pdata->name;
    /* folosind ps1, ps2 putem copia ceva in structura respectiva */
    memcpy(p_s2, p_s1, 6);
    pdata->n = 101;
    pdata->x = 999.99;
    /* se termina procesul fiu si se transmite 0 ca si valoare de iesire*/
    exit(0);
}