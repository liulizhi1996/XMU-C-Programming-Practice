#include <stdio.h>

int is_leap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    else
        return 0;
}

int main()
{
    int m, n;
    int year;
    int column_count;

    scanf("%d %d", &m, &n);
    column_count = 0;
    for (year = m; year <= n; ++year)
    {
        if (is_leap(year))
        {
            printf("%d ", year);
            column_count++;
            if (column_count == 5)
            {
                printf("\n");
                column_count = 0;
            }
        }
    }

    return 0;
}
