#include <stdio.h>

int main()
{
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");

    int numbers[100];
    int num_count = 0, min_count = 0, pl_count = 0;
    while (fscanf(input_file, "%d", &numbers[num_count]) == 1)
    {
        num_count++;
        if (numbers[num_count - 1] > 0)
        {
            pl_count ++;
        }
        if (numbers[num_count - 1] < 0)
        {
            min_count ++;

        }
    }


    if (min_count != pl_count)
    {
        printf("Different number of positive and negative numbers");
        return 0;
    }

    int i, j;
    for (i = 0; i < num_count; i++)
    {
        for (j = i + 1; j < num_count; j++)
        {
            if (numbers[i] < numbers[j])
            {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    for (i = 0; i < num_count; i++)
    {
        fprintf(output_file, "%d\n", numbers[i]);
    }
}
