#include<stdio.h>

struct RectParallelepiped {
    double x1, y1, z1;
    double x2, y2, z2;
    double x3, y3, z3;
    double x4, y4, z4;
    double x5, y5, z5;
    double x6, y6, z6;
    double x7, y7, z7;
    double x8, y8, z8;
};

void inputRectParallelepiped(struct RectParallelepiped *rp)
{
    printf("Input the coordinates of the first vertex: ");
    scanf("%lf %lf %lf", &rp->x1, &rp->y1, &rp->z1);
    printf("Input the coordinates of the second vertex: ");
    scanf("%lf %lf %lf", &rp->x2, &rp->y2, &rp->z2);
    printf("Input the coordinates of the third vertex: ");
    scanf("%lf %lf %lf", &rp->x3, &rp->y3, &rp->z3);
    printf("Input the coordinates of the fourth vertex: ");
    scanf("%lf %lf %lf", &rp->x4, &rp->y4, &rp->z4);
    printf("Input the coordinates of the fifth vertex: ");
    scanf("%lf %lf %lf", &rp->x5, &rp->y5, &rp->z5);
    printf("Input the coordinates of the sixth vertex: ");
    scanf("%lf %lf %lf", &rp->x6, &rp->y6, &rp->z6);
    printf("Input the coordinates of the seventh vertex: ");
    scanf("%lf %lf %lf", &rp->x7, &rp->y7, &rp->z7);
    printf("Input the coordinates of the eighth vertex: ");
    scanf("%lf %lf %lf", &rp->x8, &rp->y8, &rp->z8);
}

void outputRectParallelepiped(struct RectParallelepiped rp)
{
    printf("The coordinates of the first vertex are: %.2lf %.2lf %.2lf\n", rp.x1, rp.y1, rp.z1);
    printf("The coordinates of the second vertex are: %.2lf %.2lf %.2lf\n", rp.x2, rp.y2, rp.z2);
    printf("The coordinates of the third vertex are: %.2lf %.2lf %.2lf\n", rp.x3, rp.y3, rp.z3);
    printf("The coordinates of the fourth vertex are: %.2lf %.2lf %.2lf\n", rp.x4, rp.y4, rp.z4);
    printf("The coordinates of the fifth vertex are: %.2lf %.2lf %.2lf\n", rp.x5, rp.y5, rp.z5);
    printf("The coordinates of the sixth vertex are: %.2lf %.2lf %.2lf\n", rp.x6, rp.y6, rp.z6);
    printf("The coordinates of the seventh vertex are: %.2lf %.2lf %.2lf\n", rp.x7, rp.y7, rp.z7);
    printf("The coordinates of the eighth vertex are: %.2lf %.2lf %.2lf\n", rp.x8, rp.y8, rp.z8);
}

int main()
{
    struct RectParallelepiped p;
    inputRectParallelepiped(&p);
    outputRectParallelepiped(p);
}
