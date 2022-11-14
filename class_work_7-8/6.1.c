#include<stdio.h>
#include<stdint.h>

int main()
{
    uint8_t n;
    scanf("%u", &n);

    int y = 1 << n;

    printf("%u", y);
}
