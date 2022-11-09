#include<stdio.h>

int main1()
{
    int arr[5], x, t;

    t = 0;
    scanf("%u%u%u%u%u", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);
    scanf("%u", &x);

    int i;
    for (i = 0; i < 5; i ++)
    {
        if (arr[i] < x)
            t ++;
    }

    printf("%u", t);
}
