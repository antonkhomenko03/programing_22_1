#include<stdio.h>
#include<stdint.h>

int hz(uint32_t x, uint32_t y)
{
    uint32_t z = x | y;
    while (z > 1)
    {
        if (z % 2 == 1)
        {
            z /= 2;
        }
        else
            return 0;
    }
    return 1;
}

int main()
{
    uint32_t x, y;
    scanf("%u%u", &x, &y);

    if (hz(x, y) == 0)
    {
        printf("Have");
    }
    else
    {
        printf("%Don't have");
    }
}
