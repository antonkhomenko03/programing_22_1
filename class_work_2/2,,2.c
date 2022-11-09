#include <stdio.h>
#include <math.h>

float gipotenuse(float x, float y)
{
    float z;
    z = sqrt(x * x + y * y);
    return z;
}

int main()
{
    float x, y, z;
    printf("x = ");
    scanf("%f", &x);
    printf("y = ");
    scanf("%f", &y);
    z = gipotenuse(x, y);
    printf("gipotenuse = %f", z);
}
