#include<stdio.h>

int main2()
{
    int n, m;
    double arr[3][3] ={{1.0, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int i, j;
    double a;
    scanf("%u%u%lf", &i, &j, &a);

    arr[i][j] = a;

    for (i = 0; i < 3; i ++)
    {
        for (j = 0; j < 3; j ++)
        {
            printf("%lf ", arr[i][j]);
        }
        printf("\n");
    }
}
