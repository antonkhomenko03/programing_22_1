#include<stdio.h>

int main5()
{
    float x, y;
    scanf("%f%f", &x, &y);

    if (x > y)
    {
        printf("%f > %f", x, y);
    }
    else if (y > x)
    {
        printf("%f < %f", x, y);
    }
    else
    {
        printf("%f = %f", x, y);
    }
}
