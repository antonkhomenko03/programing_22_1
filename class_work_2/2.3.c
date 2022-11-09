#include <stdio.h>
#include <math.h>

float heron(float x, float y, float z)
{
    float s, p;
    p = (x + y + z) / 2;
    s = sqrt(p * (p - x) * (p - y) * (p - z));
    return s;
}

int main()
{
    float x, y, z, s;
    printf("x = ");
    scanf("%f", &x);
    printf("y = ");
    scanf("%f", &y);
    printf("z = ");
    scanf("%f", &z);
    s = heron(x, y, z);
    printf("ploscha = %.2f", s);
}
