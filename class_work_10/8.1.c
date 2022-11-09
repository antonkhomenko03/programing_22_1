#include<stdio.h>

int main1()
{
    int n, m;
    int arr[3][3] ={{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int i, j;
    scanf("%u%u", &n, &m);

    for (i = 0; i < 3; i ++)
    {
        for (j = 0; j < 3; j ++)
        {
            if (arr[i][j] == m)
                arr[i][j] = n;
        }
    }

    for (i = 0; i < 3; i ++)
    {
        for (j = 0; j < 3; j ++)
        {
            printf("%u ", arr[i][j]);
        }
        printf("\n");
    }
}
