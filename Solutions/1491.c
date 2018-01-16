#include <stdio.h>
#include <string.h>

void delete_substring(char *t, char *s, char *output)
{
    int len_t = (int)strlen(t);
    int len_s = (int)strlen(s);
    int ptr_t, ptr_s, ptr_output, ptr_temp;

    ptr_t = 0;
    ptr_output = 0;
    while (ptr_t < len_t)
    {
        ptr_temp = ptr_t;
        ptr_s = 0;
        while (ptr_temp < len_t && ptr_s < len_s)
        {
            if (t[ptr_temp] != s[ptr_s])
                break;
            ptr_temp++;
            ptr_s++;
        }
        if (ptr_s == len_s)
            ptr_t += len_s;
        else
            output[ptr_output++] = t[ptr_t++];
    }
    output[ptr_output] = '\0';
}

int main()
{
    char t[1005] = { 0 };
    char s[1005] = { 0 };
    char output[1005] = { 0 };

    while (gets(t))
    {
        gets(s);
        delete_substring(t, s, output);
        printf("%s\n", output);
    }

    return 0;
}
