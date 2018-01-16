#include <stdio.h>

void fun(char *s, char *t, char *p)
{
    int map[256] = { 0 };
    int ptr_s, ptr_t, ptr_p;

    for (ptr_s = 0; s[ptr_s]; ++ptr_s)
        map[s[ptr_s]] = 1;
    ptr_p = 0;
    for (ptr_t = 0; t[ptr_t]; ++ptr_t)
    {
        if (!map[t[ptr_t]])
        {
            p[ptr_p++] = t[ptr_t];
            map[t[ptr_t]] = 1;
        }
    }
    p[ptr_p] = '\0';
}

int main()
{
    char s[105] = { 0 };
    char t[105] = { 0 };
    char p[105] = { 0 };

    gets(s);
    gets(t);
    fun(s, t, p);
    printf("%s\n", p);

    return 0;
}
