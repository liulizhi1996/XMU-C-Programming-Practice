#include <stdio.h>

void reverse(int *s, int len_s)
{
    int i, j, temp;

    for (i = 0, j = len_s-1; i < j; ++i, --j)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void add(int *a, int len_a, int *b, int len_b, int *sum, int *len_sum)
{
    int ptr_a, ptr_b, ptr_sum;
    int carry;

    reverse(a, len_a);
    reverse(b, len_b);

    ptr_a = ptr_b = ptr_sum = 0;
    carry = 0;
    while (ptr_a < len_a && ptr_b < len_b)
    {
        sum[ptr_sum] = (a[ptr_a] + b[ptr_b] + carry) % 10;
        carry = (a[ptr_a] + b[ptr_b] + carry) / 10;
        ptr_a++;
        ptr_b++;
        ptr_sum++;
    }
    while (ptr_a < len_a)
    {
        sum[ptr_sum] = (a[ptr_a] + carry) % 10;
        carry = (a[ptr_a] + carry) / 10;
        ptr_a++;
        ptr_sum++;
    }
    while (ptr_b < len_b)
    {
        sum[ptr_sum] = (b[ptr_b] + carry) % 10;
        carry = (b[ptr_b] + carry) / 10;
        ptr_b++;
        ptr_sum++;
    }
    while (carry > 0)
    {
        sum[ptr_sum] = carry % 10;
        carry /= 10;
        ptr_sum++;
    }

    reverse(a, len_a);
    reverse(b, len_b);

    *len_sum = ptr_sum;
    --ptr_sum;
    while (sum[ptr_sum] == 0)
    {
        (*len_sum)--;
        ptr_sum--;
    }
    if (ptr_sum < 0)
    {
        sum[0] = 0;
        *len_sum = 1;
        return;
    }

    reverse(sum, *len_sum);
}

void print(FILE *fp, int *s, int len)
{
    int i;
    for (i = 0; i < len; ++i)
        fprintf(fp, "%d", s[i]);
    fprintf(fp, " ");
}

int main()
{
    int k, i;
    int fib[505][110] = {{0}, {1}};
    int len_fib[505] = {1, 1};

    FILE *fp = fopen("testin.txt", "w");
    scanf("%d", &k);
    fprintf(fp, "1 ");
    for (i = 2; i <= k; ++i)
    {
        add(fib[i-1], len_fib[i-1], fib[i-2], len_fib[i-2], fib[i], &len_fib[i]);
        print(fp, fib[i], len_fib[i]);
    }
    fprintf(fp, "\n");
    fclose(fp);

    return 0;
}
