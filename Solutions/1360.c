#include <stdio.h>

const int day_of_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int is_leap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    else
        return 0;
}

int main()
{
    int year, month, day;
    int number_of_days;
    int i;

    scanf("%d/%d/%d", &year, &month, &day);

    number_of_days = 0;
    for (i = 0; i < month - 1; ++i)
        number_of_days += day_of_month[i];
    number_of_days += day;
    if (is_leap(year) && month > 2)
        number_of_days += 1;

    printf("%d\n", number_of_days);

    return 0;
}
