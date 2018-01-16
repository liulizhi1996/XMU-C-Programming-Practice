#include <stdio.h>
#include <string.h>

int is_palindrome(char *telephone)
{
    int i, j;
    int len = (int)strlen(telephone);

    for (i = 0, j = len-1; i < j; ++i, --j)
    {
        if (telephone[i] != telephone[j])
            return 0;
    }

    return 1;
}

int main()
{
    int n;
    char telephone[15] = { 0 };
    int palindrome_count;

    scanf("%d", &n);
    palindrome_count = 0;
    while (n--)
    {
        scanf("%s", telephone);
        if (is_palindrome(telephone))
            palindrome_count++;
    }
    printf("%d\n", palindrome_count);

    return 0;
}
