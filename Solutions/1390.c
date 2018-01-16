#include <stdio.h>

int ackerman(int m, int n)
{
    if (m == 0 && n > 0)
        return n + 1;
    else if (n == 0 && m > 0)
        return ackerman(m - 1, 1);
    else if (n > 0 && m > 0)
        return ackerman(m - 1, n - 1) + n;
    else
        return 0;
}

int main()
{
    int t;
    int m, n;

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &m, &n);
        printf("%d\n", ackerman(m, n));
    }

    return 0;
}
