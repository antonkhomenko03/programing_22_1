#include<stdio.h>

double ** hz5(int n)
{

   double  r[n][n];
   int i, j;

   for (i = 0; i < n; i ++)
   {
       for (j = 0; j < n; j ++)
       {
           scanf("%u", &r[i][j]);
       }
   }

   return r;
}

int hz3(double **matrix, int n)
{
    double matrix1[n][n];

    int i, j;

    for (i = 0; i < n; i ++)
    {
        for (j = 0; j < n; j ++)
        {
            matrix1[j][i] = matrix[i][j];
        }
    }
    matrix = matrix1;
}

int main()
{
    int n;
    scanf("%u", &n);
    double **a;
    a = hz5(n);
    printf("%lf", a[1][1]);
}
