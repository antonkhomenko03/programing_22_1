#include<stdio.h>

int step(k)
{
    if (k % 2 == 0)
        return k / 2;
    return (3 * k + 1) / 2;
}

int steps_quantity(n)
{
    int a = 0;
    while (n != 0)
    {
        n = step(n);
        a += 1;
    }
    return a;
}

int main()
{
    int n;
    int n_max;
    int a_max = 0;
    for (n = 1; n < 1000; n++)
    {
        if (step(n) > a_max)
        {
            a_max = step(n);
            n_max = n;
        }
    }
    printf("%i", n_max);
}
