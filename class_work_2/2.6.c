#include <stdio.h>

float decart(float x1, float x2, float y1, float y2)
{
    return sqrt((x1 - y1) * (x1 - y1) + (x2 - y2) * (x2 - y2));
}

float heron_new(float x, float y, float z)
{
    float s, p;
    p = (x + y + z) / 2;
    s = sqrt(p * (p - x) * (p - y) * (p - z));
    return s;
}

int main()
{
    float x1, x2, y1, y2, z1, z2, a, b, c, s;
    scanf("%f %f", &x1, &x2);
    printf("\n");
    scanf("%f %f", &y1, &y2);
    printf("\n");
    scanf("%f %f", &z1, &z2);
    printf("\n");
    a = decart(x1, x2, y1, y2);
    b = decart(x1, x2, z1, z2);
    c = decart(y1, y2, z1, z2);
    s = heron_new(a, b, c);
    printf("s = %f", s);
}
