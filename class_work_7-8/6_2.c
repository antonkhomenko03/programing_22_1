#include<stdio.h>
#include<stdint.h>

int main()
{
    uint16_t n;
    scanf("%u", &n);
    int k;
    scanf("%u", &k);
    int y = 1 << k;

    printf("%u", y | n);
}
