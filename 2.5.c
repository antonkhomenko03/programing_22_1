#include <stdio.h>

float Rosenbrock2d(float x, float y)
{
    float res = 100 * (x * x - y) * (x * x - y) + (x - 1) * (x - 1);
    return res;
}

int main()
{
    float x, y, res;
    printf("x = ");
    scanf("%f", &x);
    printf("y = ");
    scanf("%f", &y);
    res = Rosenbrock2d(x, y);
    printf("Rosenbrock2d(x, y) = %f", res);
}
