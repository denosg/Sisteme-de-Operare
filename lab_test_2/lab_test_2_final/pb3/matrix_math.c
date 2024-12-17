#include "matrix_math.h"

void addMatrix(int a[3][3], int b[3][3], int res[3][3])
{

    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            res[i][j] = res[i][j] + (a[i][j] + b[i][j]);
        }
    }
}

void multiplyMatrix(int a[3][3], int b[3][3], int res[3][3])
{

    int i, j, k;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                res[i][j] = res[i][j] + (a[i][k] * b[k][j]);
            }
        }
    }
}
