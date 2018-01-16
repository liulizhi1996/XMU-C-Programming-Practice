#include <stdio.h>

void change(int *a, int *b, int flag)
{
    if (flag > 0)
    {
        *a = *a > 0 ? *a : -*a;
        *b = *b > 0 ? *b : -*b;
    }
    else if (flag < 0)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main()
{
    int n, a, b, flag;

    scanf("%d", &n);
    while (n--)
    {
        scanf("%d %d %d", &a, &b, &flag);
        change(&a, &b, flag);
        printf("%d %d\n", a, b);
    }

    return 0;
}
