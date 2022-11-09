#include<stdio.h>

float factorialfactorial(int n)
{
    int i, f;
    f = 1;
    for (i = n; i > 0; i -=2)
    {
        f *= i;
    }
    return f;
}

int main()
{
    int n, res;
    scanf("%i", &n);

    res = factorialfactorial(n);

    printf("%i", res);
}
