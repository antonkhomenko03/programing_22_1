#include<stdio.h>

float hz_a(int n)
{
    float res = 0;
    int i;
    for (i = 1; i <= n; i++)
    {
        res = sqrt(res + 2);
    }
    return res;
}

float hz_b(int n)
{
    float res = 0;
    int i;
    for (i = n; i >= 1; i--)
    {
        res = sqrt(res + 3 * i);
    }
    return res;
}

int main()
{
    int n;
    float res;
    scanf("%i", &n);

    res = hz_a(n);

    printf("%f\n", res);
    scanf("%i", &n);

    res = hz_b(n);

    printf("%f", res);
}
