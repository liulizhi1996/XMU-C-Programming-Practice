#include <stdio.h>

int main()
{
    int n, k;
    int a[10005] = { 0 };
    int i;
    int count;

    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    scanf("%d", &k);

    count = 0;
    for (i = 0; i < n; ++i)
    {
        if (a[i] == k)
            ++count;
    }
    printf("%d\n", count);

    return 0;
}
