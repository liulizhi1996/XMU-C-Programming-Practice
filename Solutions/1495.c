#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int factor_sum(int number)
{
    int sum = 1, i;

    for (i = 2; i * i <= number; ++i)
    {
        if (number % i == 0)
        {
            if (i * i == number)
                sum += i;
            else
                sum += i + number / i;
        }
    }

    return sum;
}

int main()
{
    int m, n, i, sum;
    int intimacy[10000] = { 0 };
    int intimacy_size = 0;

    scanf("%d %d", &m, &n);
    for (i = m; i <= n; ++i)
    {
        sum = factor_sum(i);
        if (i <= sum && i == factor_sum(sum))
        {
            intimacy[intimacy_size++] = i;
            if (m <= sum && sum <= n && i != sum)
                intimacy[intimacy_size++] = sum;
        }
    }
    qsort(intimacy, intimacy_size, sizeof(int), cmp);
    for (i = 0; i < intimacy_size; ++i)
        printf("%d\n", intimacy[i]);

    return 0;
}
