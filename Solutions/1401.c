#include <stdio.h>
#include <math.h>

struct Point
{
    int x;
    int y;
};

double GetMaxAngle(struct Point A, struct Point B, struct Point C)
{
    double angle_a, angle_b, angle_c;
    double a, b, c;
    double max;

    a = sqrt((B.x - C.x) * (B.x - C.x) + (B.y - C.y) * (B.y - C.y));
    b = sqrt((A.x - C.x) * (A.x - C.x) + (A.y - C.y) * (A.y - C.y));
    c = sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));

    angle_a = acos((b * b + c * c - a * a) / (2.0 * b * c));
    angle_b = acos((c * c + a * a - b * b) / (2.0 * c * a));
    angle_c = acos((a * a + b * b - c * c) / (2.0 * a * b));

    max = angle_a;
    if (angle_b > max)
        max = angle_b;
    if (angle_c > max)
        max = angle_c;

    return max;
}

double max_angle(struct Point array[], int n)
{
    int i, j, k;
    double max = -0x3f3f3f3f, temp;

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            for (k = 0; k < n; ++k)
            {
                temp = GetMaxAngle(array[i], array[j], array[k]);
                if (temp > max)
                    max = temp;
            }
        }
    }

    return max;
}

int main()
{
    int n, i;
    struct Point array[55];

    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d %d", &array[i].x, &array[i].y);
    printf("%.6lf\n", max_angle(array, n));

    return 0;
}
