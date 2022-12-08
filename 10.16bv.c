#include<stdio.h>
#include<stdlib.h>

struct student {
   char surname[20];
   int  group;
   float grades[3];
};


void print_info(struct student stu)
{
    printf("Surname of student: %s\n", stu.surname);
    printf("Group number: %d\n", stu.group);
    printf("Subject1 Grade: %f\n", stu.grades[0]);
    printf("Subject2 Grade: %f\n", stu.grades[1]);
    printf("Subject3 Grade: %f\n", stu.grades[2]);
}


void input_info(struct student *stu)
{
    printf("Enter student's surname : ");
    scanf("%s", &(stu->surname));

    printf("Enter student's group : ");
    scanf("%d", &(stu->group));

    printf("Enter student's Subject1 grade : ");
    scanf("%f", &(stu->grades[0]));

    printf("Enter student's Subject2 grade : ");
    scanf("%f", &(stu->grades[1]));

    printf("Enter student's Subject3 grade : ");
    scanf("%f", &(stu->grades[2]));
 }


float find_lowest(int n, struct student stu_list[n])
{
    float avarage_1, avarage_2, avarage_3;
    int j,k;

    for(j=0; j<n; j++)
    {
        avarage_1 += stu_list[j].grades[0];
        avarage_2 += stu_list[j].grades[1];
        avarage_3 += stu_list[j].grades[2];
    }
    if (avarage_1 < avarage_2)
    {
        if (avarage_1 < avarage_3)
        {
            return avarage_1 / n;
        }
        return avarage_3 / n;
    }
    return avarage_2 / n;
}

void output_students_better(struct student * best, int n, int grade)
{
    int i;
    for (i = 0; i < n; i ++)
    {
        if (best[i].grades[0] >= grade & best[i].grades[1] >= grade & best[i].grades[2] >= grade)
            print_info(best[i]);
    }
}

int main()
{
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct student stu_list[n];

    int i;
    for(i=0; i<n; i++)
    {
        input_info(&stu_list[i]);
        print_info(stu_list[i]);
    }
    printf("\nThe lowest average grade: %f\n",find_lowest(n, stu_list));
    printf("\ninput grade:");
    int n1;
    scanf("%u", &n1);
    printf("\nbest students:\n");
    output_students_better(stu_list, n, n1);

    return 0;
}
