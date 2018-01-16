#include <stdio.h>

int main()
{
    int n;
    int times;

    scanf("%d", &n);
    times = 0;
    while (n > 1)
    {
        if (n % 2 == 1)
            n = 3 * n + 1;
        else
            n /= 2;
        times++;
    }
    printf("%d\n", times);

    return 0;
}
