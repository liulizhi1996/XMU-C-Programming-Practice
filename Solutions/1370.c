#include <stdio.h>

int main()
{
    int t;
    int n;
    int score[102] = { 0 };
    int i;
    int max, min, sum;

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (i = 0; i < n; ++i)
            scanf("%d", &score[i]);

        max = -1;
        min = 101;
        sum = 0;
        for (i = 0; i < n; ++i)
        {
            if (score[i] > max)
                max = score[i];
            if (score[i] < min)
                min = score[i];
            sum += score[i];
        }
        sum -= max + min;
        printf("%.2lf\n", (double)sum / (n - 2));
    }

    return 0;
}
