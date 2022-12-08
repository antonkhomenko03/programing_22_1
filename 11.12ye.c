#include<stdio.h>

typedef struct Toy
{
    char name[30];
    double price;
    int min_age;
    int max_age;
} Toy;

void output_toy(Toy toy)
{
    printf("Name: %s\n", toy.name);
    printf("Price: %lf\n", toy.price);
    printf("Age range: %d-%d\n", toy.min_age, toy.max_age);
}

int main()
{
    FILE *fp;
    fp = fopen("toys.txt", "r");

    Toy toys[100];
    Toy nice_toys[50];
    int age1;
    double price;
    printf("Input minimal age and price:\n");
    scanf("%u%lf", &age1, &price);
    int counter = 0, nice_counter = 0;
    while (fscanf(fp, "%s", &toys[counter].name) == 1)
    {
        fscanf(fp, "%lf", &toys[counter].price);
        fscanf(fp, "%u%u", &toys[counter].min_age, &toys[counter].max_age);
        if (toys[counter].price == price && toys[counter].min_age == age1)
        {
            strcpy(nice_toys[nice_counter].name, toys[counter].name);
            nice_toys[nice_counter].price = toys[counter].price;
            nice_toys[nice_counter].min_age = toys[counter].min_age;
            nice_toys[nice_counter].max_age = toys[counter].max_age;
            nice_counter ++;
        }
        counter ++;
    }
    fclose(fp);
    int i;
    fp = fopen("binary_toy.bin", "wb");
    if (nice_counter == 0)
    {
        printf("No nice toys");
        fwrite(&("No nice toys"), sizeof ("No nice toys"), 1, fp);
    }

    for (i = 0; i < nice_counter; i ++)
    {
        output_toy(nice_toys[i]);
        fwrite(&nice_toys[i].name, sizeof nice_toys[i].name, 1, fp);
    }

    fclose(fp);
}
