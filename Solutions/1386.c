#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    char number[10] = { 0 };
    int i, j;
    char temp;

    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", number);

        if (number[0] == '-')
            i = 1;
        else
            i = 0;
        j = (int)strlen(number) - 1;

        while (i < j)
        {
            temp = number[i];
            number[i] = number[j];
            number[j] = temp;
            ++i;
            --j;
        }

        printf("%s\n", number);
    }

    return 0;
}
