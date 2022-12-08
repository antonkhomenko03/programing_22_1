#include<stdio.h>
#include<stdbool.h>

float dilennya(int n, int m)
{
    int k = 1;
    while (k * n < m)
        k *= 10;
    float e = ((k * n) * 1E16) / m;
    e = e * 1E-16;
    return e;
}

int hz2(int n, int m)
{
    int i = 0;
    int j, k, l, r1, r2, r3, d1, d2, d3;
    bool w = false;
    float y;
    k = 1;
    while (w == false)
    {
        k *= 10;


        y = dilennya(n, m);

        r1 = y * k;
        r2 = y * k * k;
        r3 = y * k * k * k;

        d1 = r1 % k;
        d2 = r2 % k;
        d3 = r3 % k;

        if (d1 == d2 & d2 == d3)
            w = true;
    }
    return d1;
}

int main()
{
    int n, m;
    scanf("%i%i", &n, &m);

    printf("%i", hz2(n, m));
}
