#include<stdio.h>


int main1()
{
    int x, x3;
    int x1 = 10;
    int x2 = 100;
    scanf("%i", &x);
    printf("Kilkist odynic: %u, kilkist desyatkiv: %u, kilkist soten: %u\n", x % 10, (x / 10) % 10, x / 100);
    printf("Suma cifr: %u\n", x % 10 + (x / 10) % 10 + x / 100);
    printf("%u", x % 10 * 100 + (x / 10) % 10 * 10 + x / 100);
}
