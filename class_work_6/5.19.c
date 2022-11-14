#include<stdio.h>
#include<math.h>

double func_19(double a, double b, double eps)
{
    printf("%lf %lf\n", tan(a), tan(b));
    double c = (a + b) / 2;

    if (b - a < eps)
        return c;
    if ((tan(a) - a) * (tan(c) - c) < 0)
        return func_19(a, c, eps);
    return func_19(c, b, eps);
}

int main()
{
    double eps;
    scanf("%lf", &eps);

    printf("%lf", func_19(0.001, 1.5, eps));
}
