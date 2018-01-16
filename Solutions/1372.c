#include <stdio.h>

int main()
{
    int n;
    int number;
    int odd_sum, even_sum;
    int i;

    scanf("%d", &n);
    odd_sum = even_sum = 0;
    for (i = 1; i <= n; ++i)
    {
        scanf("%d", &number);
        if (i % 2 == 1)
            odd_sum += number;
        else
            even_sum += number;
    }

    printf("%d\n%d\n", odd_sum, even_sum);

    return 0;
}
