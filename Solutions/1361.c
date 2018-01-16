#include <stdio.h>

#define SWAP(x, y) {int t = x; x = y; y = t;}

int gcd(int a, int b)
{
    int temp;

    if (a > b)
        SWAP(a, b)

    while (b > 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

int main()
{
    int t, m, n;
    int gcd_value;

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &m, &n);

        if (n == 0)
        {
            printf("Error!\n");
            continue;
        }

        gcd_value = gcd(m, n);
        m /= gcd_value;
        n /= gcd_value;

        if (n == 1)
            printf("%d\n", m);
        else
            printf("%d/%d\n", m, n);
    }

    return 0;
}
