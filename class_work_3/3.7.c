#include<stdio.h>

int main()
{
    float a, b, c;
    scanf("%f%f%f", &a, &b, &c);

    if (b * b - 4 * a * c < 0)
    {
        printf("0\n");
    }
    else if (b * b - 4 * a * c == 0)
    {
        printf("1\n");
        printf("x = %f\n", (-1 * b / 2 / a));
    }
    else
    {
        printf("2\n");
        printf("x = %f, x = %f\n", ((-1 * b + sqrt(b * b - 4 * a * c)) / 2 / a), ((-1 * b - sqrt(b * b - 4 * a * c)) / 2 / a));
    }
    float a1, b1, c1;
    scanf("%f%f%f", &a1, &b1, &c1);

    if (b1 * b1 - 4 * a1 * c1 < 0)
    {
        printf("0");
    }
    else if (b1 * b1 - 4 * a1 * c1 == 0)
    {
        if (-1 * b1 / 2 / a1 < 0)
        {
            printf("0");
        }
        else if (-1 * b1 / 2 / a1 == 0)
        {
            printf("1\n");
        }
        else
            printf("2\n");
    }
    else
    {
        if ((-1 * b1 + sqrt(b1 * b1 - 4 * a1 * c1)) / 2 / a1 < 0 & (-1 * b1 - sqrt(b1 * b1 - 4 * a1 * c1)) / 2 / a1 < 0)
        {
            printf("0\n");
        }
        else if (((-1 * b1 + sqrt(b1 * b1 - 4 * a1 * c1)) / 2 / a1 == 0 & (-1 * b1 - sqrt(b1 * b1 - 4 * a1 * c1)) / 2 / a1 < 0) | ((-1 * b1 + sqrt(b1 * b1 - 4 * a1 * c1)) / 2 / a1 < 0 & (-1 * b1 - sqrt(b1 * b1 - 4 * a1 * c1)) / 2 / a1 == 0))
        {
            printf("1\n");
            printf("x = 0");
        }
        else if ((((-1 * b1 + sqrt(b1 * b1 - 4 * a1 * c1)) / 2 / a1 < 0) & ((-1 * b1 - sqrt(b1 * b1 - 4 * a1 * c1)) / 2 / a1 > 0)))
        {
            printf("2\n");
            printf("x = %f, x = %f", sqrt((-1 * b1 - sqrt(b1 * b1 - 4 * a1 * c1)) / 2 / a1), -1 * sqrt((-1 * b1 - sqrt(b1 * b1 - 4 * a1 * c1)) / 2 / a1));
        }
        else if ((((-1 * b1 + sqrt(b1 * b1 - 4 * a1 * c1)) / 2 / a1 > 0) & ((-1 * b1 - sqrt(b1 * b1 - 4 * a1 * c1)) / 2 / a1 < 0)))
        {
            printf("2\n");
            printf("x = %f, x = %f", sqrt((-1 * b1 + sqrt(b1 * b1 - 4 * a1 * c1)) / 2 / a1), -1 * sqrt((-1 * b1 + sqrt(b1 * b1 - 4 * a1 * c1)) / 2 / a1));
        }
        else if (((-1 * b1 + sqrt(b1 * b1 - 4 * a1 * c1)) / 2 / a1 == 0 & (-1 * b1 - sqrt(b1 * b1 - 4 * a1 * c1)) / 2 / a1 > 0))
        {
            printf("3\n");
            printf("x = %f, x = %f, x = %f", 0, sqrt(-1 * b1 - sqrt(b1 * b1 - 4 * a1 * c1) / 2 / a1), -1 * sqrt(-1 * b1 - sqrt(b1 * b1 - 4 * a1 * c1) / 2 / a1));
        }
        else if (((-1 * b1 + sqrt(b1 * b1 - 4 * a1 * c1)) / 2 / a1 > 0 & (-1 * b1 - sqrt(b1 * b1 - 4 * a1 * c1)) / 2 / a1 == 0))
        {
            printf("3\n");
            printf("x = %f, x = %f, x = %f", 0, sqrt(-1 * b1 + sqrt(b1 * b1 - 4 * a1 * c1) / 2 / a1), -1 * sqrt(-1 * b1 + sqrt(b1 * b1 - 4 * a1 * c1) / 2 / a1));
        }
        else
        {
            printf("4\n");
            printf("x = %f, X = %f, x = %f, x = %f", sqrt(-1 * b1 + sqrt(b1 * b1 - 4 * a1 * c1) / 2 / a1), -1 * sqrt(-1 * b1 + sqrt(b1 * b1 - 4 * a1 * c1) / 2 / a1), sqrt(-1 * b1 - sqrt(b1 * b1 - 4 * a1 * c1) / 2 / a1), -1 * sqrt(-1 * b1 - sqrt(b1 * b1 - 4 * a1 * c1) / 2 / a1));
        }
    }
}
