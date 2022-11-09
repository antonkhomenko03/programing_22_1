#include<stdio.h>

float hz4()
{
    float a = 1;
    float r = 0;
    while (1 + a != 1)
    {
        a /= 2;
        r++;
    }
    return a;
}

int main()
{
    printf("%.15f", hz4());
}
