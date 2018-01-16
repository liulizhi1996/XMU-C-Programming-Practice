#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int a[105] = { 0 };
    int dump[105] = { 0 };
    int n, i, j, pos;

    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        dump[i] = a[i];
    }
    qsort(dump+1, n, sizeof(a[1]), cmp);
    for (i = 1; i <= n; ++i)
    {
        pos = 1;
        if (a[i] == dump[1])
        {
            printf("1 ");
            continue;
        }
        for (j = 2; j <= n; ++j)
        {
            if (dump[j] != dump[j-1])
                ++pos;
            if (a[i] == dump[j])
            {
                printf("%d ", pos);
                break;
            }
        }
    }
    printf("\n");

    return 0;
}
