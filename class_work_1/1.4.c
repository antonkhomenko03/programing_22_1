#include <stdio.h>

int main()
{
    float constant = 6.673E-11;

    float m1, m2, r;
    scanf("%f\n", &m1);
    scanf("%f\n", &m2);
    scanf("%f", &r);

    printf("F = %e", constant * m1 * m2 / r / r);
}
