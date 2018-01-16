#include <stdio.h>
#include <string.h>

void reverse(char *s, int len)
{
    int i, j;
    char temp;

    for (i = 0, j = len-1; i < j; ++i, --j)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void print_successor(char *s, int n)
{
    int len_s;
    int carry, dump;
    int i, j;

    len_s = (int)strlen(s);
    for (j = 1; j <= n; ++j)
    {
        reverse(s, len_s);
        if ('0' <= s[0] && s[0] <= '9')
        {
            carry = (s[0] - '0' + 1) / 10;
            s[0] = (char)((s[0] - '0' + 1) % 10 + '0');
        }
        else if ('a' <= s[0] && s[0] <= 'z')
        {
            carry = (s[0] - 'a' + 1) / 26;
            s[0] = (char)((s[0] - 'a' + 1) % 26 + 'a');
        }
        else
        {
            carry = (s[0] - 'A' + 1) / 26;
            s[0] = (char)((s[0] - 'A' + 1) % 26 + 'A');
        }
        for (i = 1; i < len_s; ++i)
        {
            if ('0' <= s[i] && s[i] <= '9')
            {
                dump = (s[i] - '0' + carry) / 10;
                s[i] = (char)((s[i] - '0' + carry) % 10 + '0');
                carry = dump;
            }
            else if ('a' <= s[i] && s[i] <= 'z')
            {
                dump = (s[i] - 'a' + carry) / 26;
                s[i] = (char)((s[i] - 'a' + carry) % 26 + 'a');
                carry = dump;
            }
            else
            {
                dump = (s[i] - 'A' + carry) / 26;
                s[i] = (char)((s[i] - 'A' + carry) % 26 + 'A');
                carry = dump;
            }
        }
        while (carry > 0)
        {
            if ('0' <= s[i-1] && s[i-1] <= '9')
            {
                dump = carry / 10;
                s[i] = (char)(carry % 10 + '0');
                carry = dump;
            }
            else if ('a' <= s[i-1] && s[i-1] <= 'z')
            {
                dump = carry / 26;
                s[i] = (char)(carry % 26 + 'a' - 1);
                carry = dump;
            }
            else
            {
                dump = carry / 26;
                s[i] = (char)(carry % 26 + 'A' - 1);
                carry = dump;
            }
            ++i;
        }
        s[i] = '\0';
        len_s = i;
        reverse(s, len_s);
        printf("%s\n", s);
    }
}

int main()
{
    char s[205] = { 0 };
    int n;

    scanf("%s %d", s, &n);
    print_successor(s, n);

    return 0;
}
