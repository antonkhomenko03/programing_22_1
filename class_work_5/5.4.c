#include<stdio.h>

float fac(i)
{
    float fac = 1;
    while (i > 1)
    {
        fac *= i;
        i--;
    }
    return fac;
}

float hz_a(n)
{
    int i;
    float mult;
    mult = 1;
    for (i = 1; i <= n; i++)
    {
        mult *= (1 + 1 / fac(i));
    }
    return mult;
}

float for_hz_b(n)
{
    int i;
    float res = -1;
    for (i = 1; i <= n; i++)
        res *= (-1) * 0.5;
    return res;
}

float hz_b(n)
{
    float res = 1;
    int i;
    for(i = 1; i <= n; i++)
    {
        res *= (1 + for_hz_b(i) * i * i);
        printf("\n%f\n", res);
    }
    return res;
}

int main()
{
    int n;
    scanf("%i", &n);

    printf("%f\n", hz_a(n));

    scanf("%i", &n);

    printf("%f\n", hz_b(n));
}
