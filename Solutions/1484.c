#include <stdio.h>

int main()
{
    int n, i;
    double score;
    double average = 0.0;
    int above_90 = 0, above_80 = 0, above_70 = 0, above_60 = 0, fail = 0;

    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        scanf("%lf", &score);
        average += score;
        if (score >= 90)
            ++above_90;
        else if (score >= 80)
            ++above_80;
        else if (score >= 70)
            ++above_70;
        else if (score >= 60)
            ++above_60;
        else
            ++fail;
    }
    average /= n;
    printf("%.1lf %d %d %d %d %d\n", average, above_90, above_80, above_70, above_60, fail);

    return 0;
}
