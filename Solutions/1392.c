#include <stdio.h>

#define INF 0x3F3F3F3F
#define ABS(x) ((x) > 0 ? (x) : (-(x)))

int main()
{
    int n;
    int a[10005] = { 0 };
    int summary[10005] = { 0 };
    int sum;
    int min;
    int split_point;
    int diff;
    int i;

    scanf("%d", &n);
    sum = 0;
    for (i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        sum += a[i];
        summary[i] = sum;
    }

    min = INF;
    split_point = 0;
    for (i = 1; i <= n; ++i)
    {
        diff = ABS(sum - 2 * summary[i]);
        if (diff < min)
        {
            min = diff;
            split_point = i;
        }
    }

    printf("%d\n", split_point);

    return 0;
}
