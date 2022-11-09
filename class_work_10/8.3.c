#include<stdio.h>
#define M 20
#define N 20

void hz4()
{
    double hz1[M][N];

    size_t n, m;
    scanf("%zu %zu", &m, &n);

    if (n >= N || m >= M)
        printf("Uncorrect size");

    int i, j;

    for (i = 0; i < m; i ++)
    {
        for (j = 0; j < n; j ++)
        {
            printf("matrix[%u][%u]: ", i, j);
            scanf("%lf", &hz1[i][j]);
        }
    }
}

int main3()
{
    hz4();
}
