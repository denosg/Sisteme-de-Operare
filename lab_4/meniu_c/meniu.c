#include <stdio.h>

int main()
{
    int optiune;
    do
    {
        printf("Alege un numar de la 0 la 3:");
        scanf("%d", &optiune);
    } while (optiune < 0 || optiune > 3);
    return optiune;
}