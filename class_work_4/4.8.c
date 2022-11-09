#include<stdio.h>

int hz2(int m)
{
    int k = 0;
    int k4 = 1;
    while (k4 <= m)
    {
        k += 1;
        k4 *= 4;
    }
    return k - 1;
}

int main()
{
    int m;
    scanf("%i", &m);

    printf("%i", hz2(m));
}
