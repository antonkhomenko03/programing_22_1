#include<stdio.h>

double s_eps(double x, double eps)
{
    double a0 = x;
    double a1 = -1 * x * x * x / 6;
    double sum = a0 + a1;
    double k = 2;
    while (a1 * a1 > eps * eps)
    {
        a1 = a1 * (-1) * x * x / k / (2 * k) / (2 * k + 1);
        sum += a1;
        k += 1;
    }
    printf("%lf\n%", k);

    return sum;
}

int main()
{
    double x, eps;
    scanf("%lf%lf", &x, &eps);
    double sum = s_eps(x, eps);
    printf("%lf", sum);
}
