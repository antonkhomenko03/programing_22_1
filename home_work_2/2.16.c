#include <stdio.h>

float vidstan_do_tochky(float x0, float y0, float x1, float y1)
{
    return sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
}

float vidstan_do_pryamoi(float x0, float y0, float a, float b, float c)
{
    return (a * x0 + b * y0 + c) / sqrt(a * a + b * b);
}

int main()
{
    float x0, y0, x1, y1, a, b, c, s1, s2, x2, y2;
    printf("x0 = ");
    scanf("%f", &x0);
    printf("y0 = ");
    scanf("%f", &y0);
    printf("x1 = ");
    scanf("%f", &x1);
    printf("y1 = ");
    scanf("%f", &y1);
    printf("a = ");
    scanf("%f", &a);
    printf("b = ");
    scanf("%f", &b);
    printf("c = ");
    scanf("%f", &c);

    s1 = vidstan_do_tochky(x0, y0, x1, y1);
    s2 = vidstan_do_pryamoi(x0, y0, a, b, c);
    x2 = (b * c - c) / (1 - a * b);
    y2 = -1 * a * x2 - c;

    printf("distance to point from point = %f\n", s1);
    printf("distance to line from point = %f\n", s2);
    printf("(%f, %f) - point of intersection", x2, y2);
}
