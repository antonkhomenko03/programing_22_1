#include <stdio.h>
#include <math.h>

float sinus(float x, int n)
{
    int i;
    for (i = 0; i < n; i += 1)
    {
        x = sin(x);
    }
    return x;
}

int main()
{
    float x, y;
    int n;

    scanf("%f%i", &x, &n);

    y = sinus(x, n);

    printf("%f", y);
}
