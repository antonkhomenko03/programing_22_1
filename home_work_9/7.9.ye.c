#include<stdio.h>

int main()
{
    int n;
    scanf("%u", &n);

    int arr[n], i;

    for (i = 0; i < n; i ++)
    {
        scanf("%i", &arr[i]);
    }

    int k = arr[0] * -1;
    int u = 1;
    for (i = 1; i < n; i ++)
    {
        if (arr[i] * u > k)
        {
            k = arr[i] * u;
            u *= -1;
        }
    }

    printf("%i", k);

}
