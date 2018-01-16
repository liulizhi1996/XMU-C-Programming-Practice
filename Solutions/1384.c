#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int n, k;
    int a[1005] = { 0 };
    int i, j;
    int is_found;

    scanf("%d %d", &n, &k);
    for (i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    qsort(a, n, sizeof(a[0]), cmp);

    i = 0;
    j = n - 1;
    is_found = 0;
    while (i < j)
    {
        if (a[i] + a[j] == k)
        {
            is_found = 1;
            break;
        }
        else if (a[i] + a[j] < k)
            ++i;
        else
            --j;
    }
    if (is_found)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
