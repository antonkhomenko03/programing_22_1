#include<stdio.h>
#include<math.h>

double exp_eps(double x, double eps)
{
    double a1 = 1;
    double sum = a1;
    double k = 1;
    while (a1 > eps)
    {
        a1 *= x / k;
        sum += a1;
        k += 1;
    }
    return sum;
}

double func_b(double x, double eps)
{
    double a1 = x;
    double a2 = -1 * x * x * x / 3;
    double sum = a1 + a2;
    double k = 5;
    while (a2 * a2 > eps * eps)
    {
        a2 *= -1 * x * x / k / (k - 3);
        sum += a2;
        k += 2;
    }
    return sum;
}

int main11()
{
    double x, eps;
    scanf("%lf%lf", &x, &eps);

    double sum = exp_eps(x, eps);
    double sum1 = exp(x);

    printf("%lf %lf\n", sum, sum1);

    scanf("%lf%lf", &x, &eps);

    sum = func_b(x, eps);

    printf("%lf\n", sum);
}
