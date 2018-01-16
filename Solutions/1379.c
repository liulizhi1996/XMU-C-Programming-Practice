#include <stdio.h>

int main()
{
    int m, n;
    int a[10005] = { 0 };
    int b[10005] = { 0 };
    int merge[20005] = { 0 };
    int i, j, k;

    scanf("%d %d", &m, &n);
    for (i = 0; i < m; ++i)
        scanf("%d", &a[i]);
    for (i = 0; i < n; ++i)
        scanf("%d", &b[i]);

    for (i = 0, j = 0, k = 0; i < m && j < n; )
    {
        if (a[i] >= b[j])
        {
            merge[k] = a[i];
            ++i;
            ++k;
        }
        else
        {
            merge[k] = b[j];
            ++j;
            ++k;
        }
    }
    for ( ; i < m; ++i, ++k)
        merge[k] = a[i];
    for ( ; j < n; ++j, ++k)
        merge[k] = b[j];

    for (i = 0; i < k; ++i)
        printf("%d ", merge[i]);
    printf("\n");

    return 0;
}
