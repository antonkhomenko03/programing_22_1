#include<stdio.h>

double *hz61(double *x, int x1)
{
    int i;
    double a;

    for (i = 0; i < x1; i ++)
    {
        scanf("%lf", &a);
        x[i] = a;
    }
    return 0;
}

double *hz62(double *x, int x1)
{
    int i;

    for (i = 0; i < x1; i ++)
    {
        printf("%lf ", x[i]);
    }
    return 0;
}

double *hz63(double *x, double *y, int x1)
{
    int i;

    for (i = 0; i < x1; i ++)
    {
        x[i] += y[i];
    }
    return 0;
}

double *hz64(double *x, double *y, int x1)
{
    int i;

    for (i = 0; i < x1; i ++)
    {
        x[i] *= y[i];
    }
    return 0;
}

int main()
{
    int x1;
    printf("Arrays size: ");
    scanf("%i", &x1);
    double x[x1];
    double y[x1];

    printf("Array x:\n");
    hz61(x, x1);
    printf("Array y:\n");
    hz61(y, x1);

    printf("Array x: ");
    hz62(x, x1);
    printf("\n");

    printf("Array y: ");
    hz62(y, x1);
    printf("\n");

    hz63(x, y, x1);

    printf("Array x = x + y: ");
    hz62(x, x1);
    printf("\n");

    hz64(x, y, x1);
    printf("Array x = x * y: ");
    hz62(x, x1);
}
