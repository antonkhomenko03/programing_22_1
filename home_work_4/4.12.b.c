#include<stdio.h>

float hz(float x, int n)
{
    float res, x1, x3;
    int i, j;
    res = 0;
    for (i = 0; i <= n; i++)
    {
        x3 = 1;
        x1 = 1;
        for (j = 1; j <= i; j++)
            x3 *= 3;
        for (j = 1; j <= x3; j++)
            x1 *= x;
        res += x1;
        printf("\n%f %f %f\n", x3, x1, res);
    }
    return res - x + 1;
}

int main()
{
    int n;
    float x;
    scanf("%f%i", &x, &n);

    printf("%f", hz1(x, n));
}
