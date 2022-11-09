#include<stdio.h>
#include<stdint.h>

int main()
{
    uint32_t m, x, y;
    scanf("%u", &m);
    x = m >> 24;
    y = m << 24;

    m = m << 8 >> 16 << 8;

    printf("%u\n", y | m | x);
    printf("%x", y | m | x);
}
