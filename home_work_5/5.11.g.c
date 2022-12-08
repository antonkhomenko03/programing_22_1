#include<stdio.h>

float sn(float n)
{
    float a1 = 0;
    float a2 = 1;
    float fac = 2;
    float i, an;
    float sn = 2;
    for (i = 3; i <= n; i++)
    {
        an = a2 + a1 / fac;
        fac *= i;
        a1 = a2;
        a2 = an;
        sn += an * fac;
    }
    return sn;
}

int main1()
{
    float n;
    scanf("%f", &n);

    printf("%f", sn(n));
}
