#include <stdio.h>

int * hz1( )
{

   static int  r[5];
   int i;

   for (i = 0; i < 5; i ++)
   {
       scanf("%u", &r[i]);
   }

   return r;
}

int hz2 (int r[5])
{
    int u = r[0];
    int i;

    for (i = 0; i < 5; i ++)
    {
        if (r[i] > u)
            u = r[i];
    }
    return u;
}

int main4()
{

   int *p;

   p = hz1();

   int x = hz2(p);

   printf("%u", x);
}
