#include <stdio.h>

int main()
{
    float x;
    scanf("%f", &x);

    int y = x;
    float drobova_chastyna;
    int okruglene, cila_chastyna, naymenshe_cile_bilshe_x, naybilshe_cile_menshe_x;
    if (y == x)
    {
        cila_chastyna = x;
        drobova_chastyna = x - cila_chastyna;
        naymenshe_cile_bilshe_x = cila_chastyna + 1;
        naybilshe_cile_menshe_x = cila_chastyna - 1;

    }
    else if (x >= 0)
    {
        cila_chastyna = x;
        drobova_chastyna = x - cila_chastyna;
        naymenshe_cile_bilshe_x = cila_chastyna + 1;
        naybilshe_cile_menshe_x = cila_chastyna;
    }
    else
    {
        cila_chastyna = x - 1;
        drobova_chastyna = x - cila_chastyna;
        naymenshe_cile_bilshe_x = cila_chastyna + 1;
        naybilshe_cile_menshe_x = cila_chastyna;
    }
    if (drobova_chastyna < 0.5)
    {
        okruglene = cila_chastyna;
    }
    else
    {
        okruglene = cila_chastyna + 1;
    }

    printf("cila_chastyna = %i, drobova_chastyna = %f, naymenshe_cile_bilshe_x = %i, naybilshe_cile_menshe_x = %i, okruglene = %i", cila_chastyna, drobova_chastyna, naymenshe_cile_bilshe_x, naybilshe_cile_menshe_x, okruglene);
}
