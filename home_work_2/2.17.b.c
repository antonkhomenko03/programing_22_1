#include <stdio.h>

float identity(float x)
{
    return (sqrt(x * x + 1) - 1) /  2 + x;
}

float identity_derivative(float x)
{
    return x / 2 / sqrt(x * x + 1) + 1;
}

int main()
{
    float x;
    scanf("%f", &x);
    printf("%f\n%f", identity(x), identity_derivative(x));
}
