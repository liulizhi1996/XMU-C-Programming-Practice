#include <stdio.h>

void find_two_largest(int a[], int n, int *largest, int *second_largest)
{
    int i;

    *largest = a[0];
    *second_largest = a[0];
    for (i = 0; i < n; ++i)
    {
        if (a[i] > *largest)
        {
            *second_largest = *largest;
            *largest = a[i];
        }
        else if (a[i] > *second_largest)
            *second_largest = a[i];
    }
}

int main()
{
    int n, i, largest, second_largest;
    int a[100005] = { 0 };

    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    find_two_largest(a, n, &largest, &second_largest);
    printf("%d %d\n", largest, second_largest);

    return 0;
}
