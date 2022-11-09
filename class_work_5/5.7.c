#include<stdio.h>

float k2(float k)
{
    int i;
    int k2 = 1;
    for(i = 1; i <= k; i++)
        k2 *= 2;
}

float sn(float k)
{
    float a1 = 1;
    float a0 = 0;
    float b1 = 0;
    float b0 = 1;
    float sn = 0;
    float b2, a2, i;

    for(i = 1; i <= k; i++)
    {
        sn += k2(i) / a1 + b1;
        a0 = a1;
        b0 = b1;
        b2 = b1 + a1;
        a2 = (a1 - 1) / i + a0 * b2;
        a1 = a2;
        b1 = b2;
    }
    return sn;
}

int main()
{
    float n;
    scanf("%f", &n);
    printf("%f", sn(n));
}
