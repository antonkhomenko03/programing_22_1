#include<stdio.h>

void rotate(int n, double matr[n][n])
{
    double a[n][n];
    int i, j, l, o;

    for (l = 0; l < n; l ++)
    {
        for (i = 0; i < n; i ++)
        {
            a[l][i] = matr[l][i];
        }
    }

    for (i = 0; i < n; i ++)
    {
        for (l = 0; l < n; l ++)
        {
            matr[i][l] = a[n - 1 - l][i];
        }

    }
}

int main22()
{
    double matr[6][6] = {1, 2, 3, 4, 5, 6,
                         7, 8, 9, 10, 11, 12,
                         13, 14, 15, 16, 17, 18,
                         19, 20, 21, 22, 23, 24,
                         25, 26, 27, 28, 29, 30,
                         31, 32, 33, 34, 35, 36};

    double * a1[]={(double*)&matr[0], (double*)&matr[1], (double*)&matr[2], (double*)&matr[3], (double*)&matr[4], (double*)&matr[5]};

    int k, i, j;

    rotate(6, *a1);

    for(i = 0; i < 6; i ++)
    {
        printf("\n");
        for(j = 0; j < 6; j ++)
        {
            printf("%lf ", a1[i][j]);
        }
    }
}

