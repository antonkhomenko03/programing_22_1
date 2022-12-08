#include<stdio.h>

double hz(double eps)
{
    double a0 = 1;
    double b0 = 1 / sqrt(2);
    double t0 = 0.25;
    double p0 = 1;
    double a1 = (a0 + b0) / 2;
    double b1 = sqrt(a0 * b0);
    double p1 = 2 * p0;
    double t1 = t0 - p0 * (a0 - a1) * (a0 - a1);
    double an, bn, pn, tn;

    while (((a1 + b1) * (a1 + b1) / 4 / t1 - (a0 + b0) * (a0 + b0) / 4 / t0) * ((a1 + b1) * (a1 + b1) / 4 / t1 - (a0 + b0) * (a0 + b0) / 4 / t0) > eps * eps)
    {
        double an = (a1 + b1) / 2;
        double bn = sqrt(a1 * b1);
        double pn = 2 * p1;
        double tn = t1 - p1 * (a1 - an) * (a1 - an);
        a1 = an;
        b1 = bn;
        p1 = pn;
        t1 = tn;
        a0 = a1;
        b0 = b1;
        p0 = p1;
        t0 = t1;
    }

    return (a1 + b1) * (a1 + b1) / 4 / t1;
}

int main()
{
    double eps;
    scanf("%lf", &eps);

    printf("%.16lf", hz(eps));
}
