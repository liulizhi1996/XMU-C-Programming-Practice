#include <stdio.h>

int main()
{
    int L, k;
    int a[100005] = { 0 };
    int is_found;
    int i;

    scanf("%d %d", &L, &k);
    for (i = 1; i <= L; ++i)
        scanf("%d", &a[i]);

    is_found = 0;
    for (i = 1; i <= L; ++i)
    {
        if (a[i] == k)
        {
            is_found = 1;
            break;
        }
    }

    if (is_found)
        printf("%d\n", i);
    else
        printf("Error!\n");

    return 0;
}
