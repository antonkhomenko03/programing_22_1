#include<stdio.h>

int hz3(int n)
{
    int r = 0;
    int r2 = 1;
    while (r2 <= n)
    {
        r += 1;
        r2 *= 2;
    }
    return r2;
}

int main()
{
    int n;
    scanf("%i", &n);

    printf("%i", hz3(n));
}
