#include <stdio.h>

int has_pattern(char *text, char *pattern)
{
    char *ptr_text, *ptr_pattern, *temp;

    ptr_text = text;
    while (*ptr_text)
    {
        ptr_pattern = pattern;
        temp = ptr_text;
        while (*ptr_pattern && *temp)
        {
            if (*ptr_pattern != *temp)
                break;
            ptr_pattern++;
            temp++;
        }
        if (!*ptr_pattern)
            return 1;
        ptr_text++;
    }

    return 0;
}

int main()
{
    int n, i, count;
    char text[25] = { 0 };
    char pattern[15] = { 0 };

    scanf("%d", &n);
    getchar();
    gets(text);
    count = 0;
    for (i = 0; i < n; ++i)
    {
        gets(pattern);
        count += has_pattern(text, pattern);
    }
    printf("%d\n", count);

    return 0;
}
