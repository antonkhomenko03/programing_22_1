#include<stdio.h>

int main3()
{
    int a, b, c;
    scanf("%i%i%i", &a, &b, &c);
    unsigned long int dob;
    dob = a * b * c;

    printf("%Lu\n", dob);

    unsigned long int a1, b1, c1;
    scanf("%i%i%i", &a1, &b1, &c1);
    unsigned long long int dob1;
    dob1 = a1 * b1 * c1;

    printf("%Lu", dob1);
}
