#include<stdio.h>

float func_a(float x, int n)
{
    int i, j;
    float x1;
    float y = 0;
    for (i = n; i >= 0; i -= 1)
    {
        x1 = 1;
        for (j = 0; j < i; j += 1)
        {
            x1 *= x;
        }
        y += x1;
    }
    return y;
}

float func_b(float x, float y, int n)
{
    int i, j, k, l;
    float x1, x2, y1;
    float res = 0;
    for (i = n; i >= 0; i -= 1)
    {
        x1 = 1;
        x2 = 1;
        y1 = 1;
        for (k = 1; k <= i; k += 1)
        {
            x2 *= 2;
        }
        for (j = 0; j < x2; j += 1)
        {
            x1 *= x;
        }
        for (l = 0; l < i; l += 1)
        {
            y1 *= y;
        }
        res += y1 * x1;
    }
    return res;
}

int main()
{
    float x, y, res;
    int n;

    scanf("%f%i", &x, &n);
    res = func_a(x, n);
    printf("%f\n", res);

    scanf("%f%f%i", &x, &y, &n);
    res = func_b(x, y, n);
    printf("%f", res);
}
