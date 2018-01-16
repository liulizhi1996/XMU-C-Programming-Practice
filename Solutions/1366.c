#include <stdio.h>
#include <string.h>

#define MAX_SIZE    15
#define SWAP(x, y)  { int t = x; x = y; y = t; }

void reverse(char *s, int len)
{
    int i, j;

    for (i = 0, j = len-1; i < j; ++i, --j)
        SWAP(s[i], s[j]);
}

int main()
{
    char a[MAX_SIZE] = { 0 };
    char b[MAX_SIZE] = { 0 };
    char sum[MAX_SIZE] = { 0 };
    int ptr_a, ptr_b, ptr_sum;
    int len_a, len_b;

    scanf("%s %s", a, b);

    len_a = (int)strlen(a);
    len_b = (int)strlen(b);
    reverse(a, len_a);
    reverse(b, len_b);

    ptr_a = ptr_b = ptr_sum = 0;
    while (ptr_a < len_a && ptr_b < len_b)
    {
        sum[ptr_sum] = (char)(((a[ptr_a] - '0') + (b[ptr_b] - '0')) % 10 + '0');
        ptr_a++;
        ptr_b++;
        ptr_sum++;
    }
    while (ptr_a < len_a)
    {
        sum[ptr_sum] = (char)((a[ptr_a] - '0') % 10 + '0');
        ptr_a++;
        ptr_sum++;
    }
    while (ptr_b < len_b)
    {
        sum[ptr_sum] = (char)((b[ptr_b] - '0') % 10 + '0');
        ptr_b++;
        ptr_sum++;
    }
    ptr_sum--;

    while (ptr_sum >= 0 && sum[ptr_sum] == '0')
        ptr_sum--;
    if (ptr_sum < 0)
        printf("0\n");
    else
    {
        while (ptr_sum >= 0)
            putchar(sum[ptr_sum--]);
        printf("\n");
    }

    return 0;
}
