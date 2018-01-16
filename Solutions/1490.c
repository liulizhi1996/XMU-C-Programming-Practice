#include <stdio.h>
#include <string.h>

int is_subseqence(char *t, char *s)
{
    int ptr_t, ptr_s, ptr_temp;
    int len_t, len_s;

    len_t = (int)strlen(t);
    len_s = (int)strlen(s);
    for (ptr_t = 0; ptr_t <= len_t - len_s; ptr_t++)
    {
        ptr_s = 0;
        ptr_temp = ptr_t;
        while (ptr_s < len_s && ptr_temp < len_t)
        {
            if (t[ptr_temp] == s[ptr_s])
            {
                ptr_s++;
                ptr_temp++;
            }
            else
            {
                ptr_temp++;
            }
        }
        if (ptr_s == len_s)
            return 1;
    }

    return 0;
}

int main()
{
    char t[1005] = { 0 };
    char s[1005] = { 0 };

    while (gets(t))
    {
        gets(s);
        printf("%d\n", is_subseqence(t, s));
    }

    return 0;
}
