#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100005

int main()
{
    char text[MAX_SIZE] = { 0 };
    int len, count = 0, is_word = 0, i;

    fgets(text, MAX_SIZE, stdin);
    len = (int)strlen(text);
    for (i = 0; i < len; ++i)
    {
        if (('a' <= text[i] && text[i] <= 'z') || ('A' <= text[i] && text[i] <= 'Z'))
        {
            if (!is_word)
            {
                is_word = 1;
                count++;
            }
        }
        else
            is_word = 0;
    }

    printf("%d\n", count);

    return 0;
}
