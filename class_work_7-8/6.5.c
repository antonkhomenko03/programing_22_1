#include<stdio.h>
#include<stdint.h>

int main()
{
    uint32_t x;
    scanf("%u", &x);

    int res = 0;
    int k = 0;

    while (x > 0)
    {
        if (x & 1)
            k ++;
        else
        {
            if (res < k)
                res = k;
            k = 0;
        }
        x = x >> 1;
    }

    printf("%u", res);
}
