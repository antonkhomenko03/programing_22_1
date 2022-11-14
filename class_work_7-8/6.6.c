/*y = ((x & (x-1))>0)

y = 0 <=> x = 2 ^ n, n - φ³λε νεβ³δ'Ίμνε ΰαξ x = 0
y = 1 <=> x = 2 ^ n, n - φ³λε νεβ³δ'Ίμνε ςΰ x = 0


y = x & (-x)

y = 0 <=> x = 0
y = 1 <=> x != 0*/

#include<stdio.h>
#include<stdint.h>

int main()
{
    uint16_t a = -0;
    scanf("%u", &a);
    printf("%u\n", (a & (a - 1)) > 0);
    printf("%u", a & ~a);
}
