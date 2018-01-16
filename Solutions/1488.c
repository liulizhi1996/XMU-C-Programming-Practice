#include <stdio.h>

int is_prime(int n)
{
    int i;

    if (n == 1)
        return 0;

    for (i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int main()
{
    int n, number;
    int count = 0;
    int i;

    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        scanf("%d", &number);
        if (is_prime(number))
            count++;
    }
    printf("%d\n", count);

    return 0;
}
