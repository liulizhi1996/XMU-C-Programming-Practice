#include <stdio.h>

int is_prime(int n)
{
    int i;

    if (n == 1)
        return 0;

    for (i = 2; i*i <= n; ++i)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int main()
{
    int n;
    int i, j;

    scanf("%d", &n);
    printf("%d=", n);
    if (n % 2 == 0)
    {
        for (i = 2; i*2 <= n; ++i)
        {
            if (is_prime(i) && is_prime(n-i))
            {
                printf("%d+%d\n", i, n-i);
                break;
            }
        }
    }
    else
    {
        for (i = 2; i*3 <= n; ++i)
        {
            for (j = 2; j*2 <= n-i; ++j)
            {
                if (is_prime(i) && is_prime(j) && is_prime((n-i-j)))
                {
                    printf("%d+%d+%d\n", i, j, n-i-j);
                    return 0;
                }
            }
        }
    }

    return 0;
}
