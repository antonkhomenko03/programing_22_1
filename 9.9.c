#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

double **inputMatrix(int n, int m)
{
    int i, j;
    double **arr = (double**)malloc(n * sizeof(double*));
	for (i = 0; i < n; i++)
		arr[i] = (double*)malloc(m * sizeof(double));

    for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%lf", &arr[i][j]);

    return arr;
}


void showMatrix(const double **v, int n, int m)
{
    int i, j;
    for (i = 0; i < n; i ++)
    {
        for (j = 0; j < m; j ++)
        {
            printf("%lf ", v[i][j]);
        }
        printf("\n");
    }
}



double **OneMoreRow(int n, int m, double **v)
{
    int i, j;
    double **arr = (double**)malloc((n + 1) * sizeof(double*));
	for (i = 0; i < n + 1; i++)
		arr[i] = (double*)malloc(m * sizeof(double));

    for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			arr[i + 1][j] = v[i][j];

    return arr;
}

double **kMoreRowAfterM1(int n, int m, int k, int m1, double **v)
{
    int i, j;
    double **arr = (double**)malloc((n + 1) * sizeof(double*));
	for (i = 0; i < n + 1; i++)
		arr[i] = (double*)malloc((m + k) * sizeof(double));

    for (i = 0; i < n; i++)
    {
		for (j = 0; j < m + k; j++)
        {
            if (j < m1)
            {
                arr[i][j] = v[i][j];
            }
            else if (j < m1 + k)
            {
                arr[i][j] = 0;
            }
            else
            {
                arr[i][j] = v[i][j - k];
            }
        }
    }
    return arr;
}
void task9d()
{
    int m, n;
    scanf("%u%u", &n, &m);
    double **arr = inputMatrix(n, m);
    double **arr1 = OneMoreRow(n, m, arr);
    showMatrix(arr, n, m);
    printf("New matrix:\n");
    showMatrix(arr1, n + 1, m);
}



void task9h()
{
    int m, n, k, m1;
    scanf("%u%u%u%u", &n, &m, &k, &m1);
    double **arr = inputMatrix(n, m);
    showMatrix(arr, n, m);
    double **arr1 = kMoreRowAfterM1(n, m, k, m1, arr);
    printf("New matrix:\n");
    showMatrix(arr1, n, m + k);
}


int main()
{
    task9h();
    task9h();
}
