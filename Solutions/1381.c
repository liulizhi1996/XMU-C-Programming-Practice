#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100005

int main()
{
    int n;
    char t[MAX_SIZE] = { 0 };
    char s[MAX_SIZE] = { 0 };
    int ptr_t, ptr_s, ptr_t_temp;
    int len_t, len_s;
    int is_matched, matched_count;

    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", t);
        scanf("%s", s);

        len_t = (int)strlen(t);
        len_s = (int)strlen(s);
        matched_count = 0;
        for (ptr_t = 0; ptr_t < len_t; )
        {
            is_matched = 1;
            for (ptr_t_temp = ptr_t, ptr_s = 0; ptr_t_temp < len_t && ptr_s < len_s; ++ptr_t_temp, ++ptr_s)
            {
                if (t[ptr_t_temp] != s[ptr_s])
                {
                    is_matched = 0;
                    break;
                }
            }
            if (is_matched && ptr_s == len_s)
            {
                matched_count++;
                ptr_t += len_s;
            }
            else
                ptr_t++;
        }

        printf("%d\n", matched_count);
    }

    return 0;
}
