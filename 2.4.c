#include <stdio.h>
#include <math.h>

float func_a(float x)
{
    float x2, res;
    x2 = x * x + 1;
    res = x2 * x2;
    return res;
}

float func_b(float x)
{
    float res = (x * x * x * x * x - 1) / (x - 1);
    return res;
}

float func_v(float x)
{
    float res = (x + 1);
    res = res * res * res * res * res;
    return res;
}

float func_g(float x)
{
    float res = x * x * x;
    res = res * res * res + res + 1;
    return res;
}

float func_d(float x)
{
    float res = (32 * x * x * x * x * x - 1) / (2 * x - 1);
    return res;
}

float func_e(float x)
{
    float x2 = x * x;
    float res = x * x2 * x2 + x * x2 + x;
    return res;
}

int main()
{
    float x, res;
    scanf("%f", &x);
    res = func_a(x);
    printf("f1(x) = %f\n", res);
    res = func_b(x);
    printf("f2(x) = %f\n", res);
    res = func_v(x);
    printf("f3(x) = %f\n", res);
    res = func_g(x);
    printf("f4(x) = %f\n", res);
    res = func_d(x);
    printf("f5(x) = %f\n", res);
    res = func_e(x);
    printf("f6(x) = %f\n", res);
}
