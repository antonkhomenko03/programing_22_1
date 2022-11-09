#include<stdio.h>
#include<stdint.h>

int main()
{
    uint32_t m;
    scanf("%u", &m);
    int j;
    scanf("%u", &j);
    int y = 1 << j;

    y = ~y;

    printf("%u", y & m);
}
