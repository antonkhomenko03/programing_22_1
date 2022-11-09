#include<stdio.h>

int next_step(n1, n3)
{
    int s = n1 + n3 + 100;
    return s;
}

int posl()
{
    int n1, n2, n3;
    n1 = -99;
    n2 = -99;
    n3 = -99;
    int next_n = -1;
    int i;
    while (next_n <= 0)
    {
        next_n = next_step(n1, n3);
        n2 = n3;
        n1 = n2;
        n3 = next_n;
    }
    return next_n;
}

int main()
{
    printf("%i", posl());
}
