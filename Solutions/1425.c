#include <stdio.h>
#include <string.h>

void add(char *s, int x, char q)
{
    int len_s = (int)strlen(s);
    int i;

    s[len_s + 1] = '\0';
    for (i = len_s; i >= 0; --i)
    {
        if (i == x)
        {
            s[i] = q;
            return;
        }
        s[i] = s[i-1];
    }
}

void delete(char *s, int x)
{
    int len_s = (int)strlen(s);
    int i;

    for (i = x; i < len_s - 1; ++i)
        s[i] = s[i+1];
    s[len_s - 1] = '\0';
}

int main()
{
    char s[2005] = { 0 };
    int n;
    char operator[10] = { 0 };
    int x;
    char q;

    scanf("%s", s);
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", operator);
        if (!strcmp(operator, "add"))
        {
            scanf("%d %c", &x, &q);
            add(s, x-1, q);
        }
        else
        {
            scanf("%d", &x);
            delete(s, x-1);
        }
    }
    printf("%s\n", s);

    return 0;
}
