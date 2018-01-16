#include <stdio.h>

int main()
{
    int a[20] = { 0 };
    int n;
    int i;

    scanf("%d", &n);

    // a[i] => a[i-2] if a[i] == 1
    //      => a[i-1] if a[i] == 0
    // a[i] = a[i-2] + a[i-1]
    // initial: a[1] = 2, a[2] = 3
    a[1] = 2;
    a[2] = 3;
    for (i = 3; i <= n; ++i)
        a[i] = a[i - 1] + a[i - 2];

    printf("%d\n", a[n]);

    return 0;
}
