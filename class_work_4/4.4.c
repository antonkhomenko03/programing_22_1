#include<stdio.h>

float hz(float x, int n)
{
    float res, x1;
    int i, j;
    res = 0;
    for (i = 1; i <= n; i += 1)
    {
        x1 = 1;
        for (j = 1; j <= i; j += 1)
        {
            x1 *= x;
        }
        res += i * x1;
    }
    return res;
}

int main()
{
    float x, res;
    int n;
    scanf("%f%i", &x, &n);
    res = hz(x, n);
    printf("%f", res);
}
