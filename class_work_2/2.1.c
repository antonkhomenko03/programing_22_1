#include <stdio.h>
#include <math.h>

float cosinus(float x)
{
    float y;
    y = cos(x);
    return y;
}

int main()
{
    float x, y;
    printf("x = ");
    scanf("%f", &x);
    y = cosinus(x);
    printf("cos(x) = %f", y);
}
