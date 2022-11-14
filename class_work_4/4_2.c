#include <stdio.h>

int main()
{
    int n, i;
    scanf("%i", &n);

    printf("n! = 1");

    for (i = 2; i <= n; i += 1)
    {
        printf("*%i", i);
    }

    printf("\nn! = 1");

    for (i = n; i > 1; i -=1)
    {
        printf("*%i", n - i + 2);
    }
}
