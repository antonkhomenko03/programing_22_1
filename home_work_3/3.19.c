#include <stdio.h>

int func_a(int n)
{
    if (n % 2 == 0)
    {
        return 1;
    }
    return 0;
}

int func_b(int n)
{
    if (n % 10 == 5)
    {
        return 1;
    }
    return 0;
}

int func_v(int n, int m)
{
    if (n % m == 0)
    {
        return 1;
    }
    return 0;
}

int func_g(int n, int m, int k)
{
    if (n % m == 0 & k % m == 0)
    {
        return 1;
    }
    return 0;
}

int main1()
{
    int m, n, k, r;
    printf("n = ");
    scanf("%i", &n);
    r = func_a(n);
    printf("%i\n", r);
    printf("n = ");
    scanf("%i", &n);
    r = func_b(n);
    printf("%i\n", r);
    printf("n = ");
    scanf("%i", &n);
    printf("m = ");
    scanf("%i", &m);
    r = func_v(n, m);
    printf("%i\n", r);
    printf("n = ");
    scanf("%i", &n);
    printf("m = ");
    scanf("%i", &m);
    printf("k = ");
    scanf("%i", &k);
    r = func_g(n, k, m);
    printf("%i\n", r);
}
