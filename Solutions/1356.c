#include <stdio.h>

int g(int x)
{
    return x * x - 550;
}

int f(int x)
{
    int g_x = g(x);

    if (x < g_x)
        return g_x + x + 4;
    else
        return g_x - x;
}

int main()
{
    int x;

    scanf("%d", &x);
    printf("%d\n", f(x));

    return 0;
}
