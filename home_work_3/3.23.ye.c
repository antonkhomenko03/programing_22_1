#include <stdio.h>
#include <math.h>

double  softExponential(double a, double x)
{
    if (a < 0)
    {
        return -1 * log(1 - a * (x + a)) / a;
    }
    else if (a > 0)
    {
        return (exp(a * x) - 1) / a + a;
    }
    else
        return x;
}

double derivative(double a, double x)
{
    double w;
    if (a < 0)
    {
        if (1 - a * (a + x) == 0)
            w = 9223372036854775807;
        else
            w = 1 / (1 - a * (a + x));
    }
    else if (a == 0)
    {
        w = 1;
    }
    else
    {
        w = exp(a * x);
    }
    return w;
}

int main()
{
    double a, x, y, z;
    scanf("%d%d", &a, &x);

    y = derivative(a, x);
    printf("%d\n", y);
    z = derivative(a, x);

}
