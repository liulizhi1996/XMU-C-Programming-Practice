#include <stdio.h>

int partition(int *a, int low, int high)
{
    int mid = (low + high) / 2;
    a[0] = a[mid];
    a[mid] = a[low];

    while (low < high)
    {
        while (low < high && a[high] <= a[0])
            --high;
        a[low] = a[high];
        while (low < high && a[low] >= a[0])
            ++low;
        a[high] = a[low];
    }
    a[low] = a[0];

    return low;
}

void quicksort(int *a, int low, int high)
{
    if (low >= high)
        return;
    int pivot = partition(a, low, high);
    quicksort(a, low, pivot-1);
    quicksort(a, pivot+1, high);
}

int main()
{
    int n, i;
    int a[105] = { 0 };

    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    quicksort(a, 1, n);

    for (i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
