#include<stdio.h>

int main2()
{
    int x;
    scanf("%i", &x);
    int x1 = x % 10;
    int x2 = x / 10 % 10;
    int x3 = x / 100;
    if (x1 != x2 & x1 != x3 & x2 != x3)
    {
        int a[3] = {x1, x2, x3};
        int i, j, k;
        for (i = 0; i < 3; i++)
        {
            for(j = 0; j < 3; j++)
            {
                for (k = 0; k < 3; k++)
                {
                    if (i != j & j != k & k != i)
                    {
                        printf("\n%u", a[i] * 100 + a[j] * 10 + a[k]);
                    }
                }
            }
        }
    }
}
