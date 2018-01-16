#include <stdio.h>

int main()
{
    int t;
    char binary[35] = { 0 };
    int decimal;
    int i;

    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", binary);

        decimal = 0;
        i = 0;
        while (binary[i])
        {
            decimal = decimal * 2 + (binary[i] - '0');
            ++i;
        }
        printf("%d\n", decimal);
    }

    return 0;
}
