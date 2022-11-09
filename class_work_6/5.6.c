#include<stdio.h>

float hz2_a(float b, float n)
{
    int i;
    float res = b + 1 / b;
    for (i = 0; i <= n; i++)
        res = b + 1 / res;
    return res;
}

float hz2_b(float n)
{
    float i;
    float res = 4 * n - 2 + 1 / (4 * n + 2);
    for (i = n - 2; i >= 0; i--)
        res = (4 * i + 2) + 1 / res;
    return res;
}

float hz2_c(float n)
{
    float i;
    float res = 1.0 + 1.0 / (2.0 + 1.0 / 2.0);
    printf("%f\n", res);
    for (i = n - 2; i >= 0; i--)
        res = 1 + 1 / (2 + 1 / res);
    return res;
}

int main1()
{
    int n;
    float b;
    scanf("%i%f", &n, &b);

    printf("%f\n", hz2_a(b, n));

    scanf("%i", &n);

    printf("%f\n", hz2_b(n));

    scanf("%i", &n);

    printf("%f\n", hz2_c(n));
}
