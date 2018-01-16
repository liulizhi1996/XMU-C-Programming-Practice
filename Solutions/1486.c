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

int k_most(int *a, int low, int high, int k)
{
    int pivot = partition(a, low, high);
    if (pivot == k)
        return a[pivot];
    else if (pivot < k)
        return k_most(a, pivot+1, high, k);
    else
        return k_most(a, low, pivot-1, k);
}

int main()
{
    int n, k;
    int array[105] = { 0 };
    int i;

    scanf("%d %d", &n, &k);
    for (i = 1; i <= n; ++i)
        scanf("%d", &array[i]);
    printf("%d\n", k_most(array, 1, n, k));

    return 0;
}
