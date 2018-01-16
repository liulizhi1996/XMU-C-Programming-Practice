#include <stdio.h>

const char map[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

void convert(int n, int m)
{
    if (n == 0)
        return;
    convert(n/m, m);
    printf("%c", map[n % m]);
}

int main()
{
    int t, n, m;

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &n, &m);
        convert(n, m);
        printf("\n");
    }

    return 0;
}
