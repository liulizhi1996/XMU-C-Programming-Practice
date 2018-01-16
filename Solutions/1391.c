#include <stdio.h>

#define PI 3.14159

int main()
{
    double r;

    scanf("%lf", &r);
    printf("%.2lf\n", 2 * PI * r);
    printf("%.2lf\n", PI * r * r);
    printf("%.2lf\n", 4 * PI * r * r);
    printf("%.2lf\n", 4.0 / 3.0 * PI * r * r * r);

    return 0;
}
