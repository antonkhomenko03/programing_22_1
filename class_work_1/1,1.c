#include <stdio.h>
#include <float.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main()
{
    printf("2 + 31 = %i\n", 2 + 31);
    printf("45 * 54 - 11 = %i\n", 45 * 54 -11);
    printf("15 / 4 = %i\n", 15 / 4);
    printf("15.0 / 4 = %f\n", 15.0 / 4);
    printf("67 ostacha vid dilennya 5 = %i\n", 67 % 5);
    printf("(2 * 45.1 + 3.2) / 2 = %f\n", (2 * 45.1 + 3.2) / 2);


    float a1 = 0.0001;
    double b1 = 0.0001;
    long double c1 = 0.0001L;
    printf("%.2f %.2f %.2Lf\n", a1, b1, c1);

    float a2 = M_PI;
    double b2 = M_PI;
    long double c2 = M_PI;
    printf("%.2f %.2f %.2Lf\n", a2, b2, c2);

    float a3 = 24.33E5;
    double b3 = 24.33E5;
    long double c3 = 24.33e5L;
    printf("%.2f %.2f %Lf\n", a3, b3, c3);

    float a4 = M_E;
    double b4 = M_E;
    long double c4 = M_E;
    printf("%.2f %.2f %Lf\n", a4, b4, c4);

    float a5 = sqrt(5);
    double b5 = sqrt(5);
    long double c5 = sqrt(5);
    printf("%.2f %.2f %.2Lf\n", a5, b5, c5);

    float a6 = log(100);
    double b6 = log(100);
    long double c6 = log(100);
    printf("%.2f %.2f %.2Lf", a6, b6, c6);

    long double r = 24324L;
    printf("%Lg", r);
}

