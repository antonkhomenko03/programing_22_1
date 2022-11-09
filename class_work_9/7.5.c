#include<stdio.h>

int * hz3(int *r, int k)
{

   static int  e[2] = {0, 0};
   int i;
   printf("%u\n", k);
   for (i = 0; i < k; i ++)
   {
       if (r[i] % 2 == 0)
       {
           e[0] += 1;
       }
       else if (r[i] % 2 == 1)
       {
           e[1] += 1;
       }
   }

   return e;
}

int main()
{
    int *arr;
    int q = 1;
    int r;
    int k = 0;

    while (q > 0)
    {
        scanf("%u", &r);
        if (r == 0)
        {
            q = 0;
        }
        else
        {
            arr[q - 1] = r;
            q += 1;
            k += 1;
        }
    }

    int *arr1;
    arr1 = hz3(arr, k);
    printf("pair: %u, odd:%u", arr1[0], arr1[1]);
}
