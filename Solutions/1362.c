#include <stdio.h>

int f(int x)
{
    if (x < 0)
        return f(f(-x));
    else
        return 5 * x - 10000;
}

int main()
{
    int n, x;

    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &x);
        printf("%d\n", f(x));
    }

    return 0;
}
