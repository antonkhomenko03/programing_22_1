#include <stdio.h>

int main()
{
    float x;
    scanf("%f", &x);

    float x2 = x * x;
    float x4 = x2 * x2;
    float x6 = x4 * x2;
    float x8 = x4 * x4;
    float x9 = x8 * x;
    float x16 = x8 * x8;
    float x15 = x16 / x;
    float x32 = x16 * x16;
    float x28 = x32 / x4;
    float x64 = x32 * x32;
    printf("x^4 = %f, x^6 = %f, x^9 = %f, x^15 = %f, x^28 = %f, x^64 = %f", x4, x6, x9, x15, x28, x32);
}
