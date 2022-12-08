#include<stdio.h>

void zsuv(int n, int m, int k, double matr[n][m])
{
    double a[n][m];
    int i, j, l, o;

    for (i = 0; i < k; i ++)
    {
        for (l = 0; l < n; l ++)
        {
            a[0][l] = matr[l][m - 1];
        }
        for (j = m - 1; j > 0; j --)
        {
            for (o = 0; o < n; o ++)
            {
                matr[o][j] = matr[o][j - 1];
            }
        }
        for (o = 0; o < n; o ++)
        {
            matr[o][0] = a[0][o];
        }

    }
}

int main()
{
    double matr[3][5] = {1, 2, 3, 4, 5,
                         6, 7, 8, 9, 10,
                         11, 12, 13, 14, 15};

    double * a1[]={(double*)&matr[0], (double*)&matr[1], (double*)&matr[2]};

    int k, i, j;
    scanf("%u", &k);

    zsuv(3, 5, k, *a1);

    for(i = 0; i < 3; i ++)
    {
        printf("\n");
        for(j = 0; j < 5; j ++)
        {
            printf("%lf ", a1[i][j]);
        }
    }
}
