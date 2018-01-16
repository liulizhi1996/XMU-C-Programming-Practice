#include <stdio.h>

int main()
{
    int L, k;
    int a[100005] = { 0 };
    int is_found;
    int i, j, mid;

    scanf("%d %d", &L, &k);
    for (i = 1; i <= L; ++i)
        scanf("%d", &a[i]);

    is_found = 0;
    i = 1;
    j = L;
    mid = 0;
    while (i <= j)
    {
        mid = (i + j) / 2;
        if (a[mid] == k)
        {
            is_found = 1;
            break;
        }
        else if (a[mid] < k)
            i = mid + 1;
        else
            j = mid - 1;
    }

    if (is_found)
        printf("%d\n", mid);
    else
        printf("Error!\n");

    return 0;
}
