#include<stdio.h>

int main3()
{
    double arr[10];
    int i;

    for (i = 0; i < 10; i++)
    {
        scanf("%lf", &arr[i]);
    }

    double ups = 0;

    for (i = 0; i < 10; i ++)
    {
        if (arr[i] > exp(1))
            ups += arr[i];
    }
    printf("%lf", ups);
}
