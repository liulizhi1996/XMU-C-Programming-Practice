#include <stdio.h>

int main()
{
    int n;
    double an, Sn;
    int i, j;

    scanf("%d", &n);
    Sn = 0;
    for (i = 1; i <= n; ++i)
    {
        an = 0;
        for (j = 1; j <= i; ++j)
            an += (double)j / (i + 1);
        Sn += an;
    }
    printf("%.4lf\n", Sn);

    return 0;
}
