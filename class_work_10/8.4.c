#include<stdio.h>
#define M 25
#define N 25

void hz2()
{
    double hz1[M][N];

    size_t n, m;
    scanf("%zu %zu", &m, &n);

    if (n >= N || m >= M)
        printf("Uncorrect size");

    int i, j;

    for (i = 0; i < m; i ++)
    {
        printf("Row %u: ", i + 1);
        for (j = 0; j < n; j ++)
        {
            scanf("%lf", &hz1[i][j]);
        }
    }
}

int main4()
{
    hz2();
}
