#include <stdio.h>
#include "matrix_math.h"

void printMatrix(int matrice[3][3])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{

    int matrice1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    int matrice2[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}};

    int suma[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};

    int produs[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};

    addMatrix(matrice1, matrice2, suma);
    printMatrix(suma);

    multiplyMatrix(matrice1, matrice2, produs);
    printMatrix(produs);

    return 0;
}