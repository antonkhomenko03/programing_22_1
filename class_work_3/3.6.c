#include<stdio.h>

int main6()
{
    float x, y, z;
    scanf("%f%f%f", &x, &y, &z);
    if (x * x > y * y & x * x > z * z & y * y > z * z)
    {
        printf("max: %f, min: %f", x, z);
    }
    if (x * x > y * y & x * x > z * z & z * z > y * y)
    {
        printf("max: %f, min: %f", x, y);
    }
    if (y * y > x * x & y * y > z * z & x * x > z * z)
    {
        printf("max: %f, min: %f", y, z);
    }
    if (y * y > x * x & y * y > z * z & z * z > x * x)
    {
        printf("max: %f, min: %f", y, x);
    }
    if (z * z > y * y & z * z > x * x & y * y > x * x)
    {
        printf("max: %f, min: %f", z, x);
    }
    if (z * z > y * y & z * z > x * x & x * x > y * y)
    {
        printf("max: %f, min: %f", z, y);
    }
}
