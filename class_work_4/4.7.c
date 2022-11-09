#include<stdio.h>

float hz1(float x, int n)
{
    int i, j, x2;
    float res, x1;
    res = 0;
    for (i = 0; i <= n; i++)
    {
        x1 = 1;
        x2 = 1;
        for (j = 1; j <= i; j++)
        {
            x1 *= x;
            x2 *= j;
        }
        printf("\n%f %f\n", x1, x2);
        res += x1 / x2;
    }
    return res;
}

int main()
{
    float x, res;
    int n;

    scanf("%f%i", &x, &n);
    res = hz1(x, n);
    printf("%f", res);
}
