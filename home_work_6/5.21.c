#include<stdio.h>

int main()
{
    double a1 = 0;
    double a2 = 0;
    double a5 = 0;
    double a10 = 0;
    double a25 = 0;
    double a50 = 0;

    double n;
    scanf("%lf", &n);

    while (n >= 50)
    {
        n -= 50;
        a50 += 1;
    }
    while (n >= 25)
    {
        n -= 25;
        a25 += 1;
    }
    while (n >= 10)
    {
        n -= 10;
        a10 += 1;
    }
    while (n >= 5)
    {
        n -= 5;
        a5 += 1;
    }
    while (n >= 2)
    {
        n -= 2;
        a2 += 1;
    }
    while (n >= 1)
    {
        n -= 1;
        a1 += 1;
    }

    printf("50 quantoty: %lf, 25 quantity: %lf, 10 quantity: %lf, 5 quantity: %lf, 2 quantity: %lf, 1 quantity: %lf", a50, a25, a10, a5, a2, a1);
}
