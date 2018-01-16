#include <stdio.h>
#include <stdlib.h>

const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    char text[1005] = { 0 };
    char cipher[20] = { 0 };
    int ptr_cipher, ptr_text;
    int n, q, m, d;

    while (fgets(text, 1005, stdin))
    {
        ptr_cipher = 0;
        for (ptr_text = 0; text[ptr_text]; ++ptr_text)
        {
            if ('0' <= text[ptr_text] && text[ptr_text] <= '9')
                cipher[ptr_cipher++] = text[ptr_text];
        }
        n = atoi(cipher);
        q = (n * 3) % 1131 + 101;
        m = q / 100;
        d = q % 38;
        printf("%d %d %d %d\n", n, q, m, d);
        if (1 <= m && m <= 12 && 0 < d && d <= days[m])
            printf("%d月%d日\n", m, d);
        else
            printf("input error!\n");
    }

    return 0;
}
