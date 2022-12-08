#include <stdio.h>
#include<math.h>
#include<stdbool.h>

int main()
{

    FILE *fp;
    fp = fopen("file1.bin", "wb");
    int val = 10;
    fwrite(&val, sizeof val, 1, fp);
    val = 11;
    fwrite(&val, sizeof val, 1, fp);
    val = 16;
    fwrite(&val, sizeof val, 1, fp);
    val = 25;
    fwrite(&val, sizeof val, 1, fp);
    val = 101;
    fwrite(&val, sizeof val, 1, fp);
    val = 100;
    fwrite(&val, sizeof val, 1, fp);
    val = 120;
    fwrite(&val, sizeof val, 1, fp);
    val = 125;
    fwrite(&val, sizeof val, 1, fp);
    fclose(fp);

    int a;
    int q = 0;
    fp = fopen("file1.bin", "rb");

    double sqr;
    int sqr1;
    int high;
    int low;

    bool parne = false;
    bool neparne = false;

    while(fread(&a, sizeof(int), 1, fp) > 0)
    {
        if (a % 2 == 0 & !parne)
        {
            high = a;
            parne = true;
        }
        if (a % 2 == 1 & !neparne)
        {
            low = a;
            neparne = true;
        }
        sqr = sqrt(a);
        sqr1 = sqr;
        if (sqr1 == sqr & a % 2 == 1)
            q ++;
        if (a % 2 == 0 & a > high & parne)
            high = a;
        if (a % 2 == 1 & a < low & neparne)
            low = a;
    }
    printf("Quantity is: %d\n", q);
    if (parne & neparne)
        printf("Difference is %d\n", high - low);
    fclose(fp);
}
