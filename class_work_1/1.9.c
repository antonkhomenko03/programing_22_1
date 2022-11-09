#include <stdio.h>

int main()
{
    float x, y;
    scanf("%f%f", &x, &y);
    float aryf = (x + y) / 2;
    float garm = sqrt(x * y);
    printf("seredne arifmetichne = %e, seredne garmonichne = %e\n", aryf, garm);
    printf("seredne arifmetichne = %f, seredne garmonichne = %f", aryf, garm);
}
