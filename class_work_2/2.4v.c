#include <stdio.h>

float func(float x)
{
    float x1 = x + 1;
    float x2 = x1 * x1;
    float x3 = x2 * x2 * x1;
    return x3;
}

int main()
{
    float x;
    scanf("%f", &x);
    printf("%f", func(x));
}
