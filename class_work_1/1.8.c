#include <stdio.h>

int main()
{
    float x, y;
    printf("x = ");
    scanf("%f", &x);
    printf("y = ");
    scanf("%f", &y);

    float dobutok = x * y;
    float chastka = x / y;

    printf("x * y = %f, x / y = %f", dobutok, chastka);
}
