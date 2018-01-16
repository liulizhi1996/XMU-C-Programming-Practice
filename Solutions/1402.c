#include <stdio.h>
#include <stdlib.h>

struct Date
{
    int year;
    int month;
    int day;
    struct Date *next;
};

void insert(struct Date *list, int year, int month, int day)
{
    struct Date *p, *q, *r;

    r = (struct Date*)malloc(sizeof(struct Date));
    r->year = year;
    r->month = month;
    r->day = day;
    r->next = NULL;

    q = list;
    p = list->next;
    while (p)
    {
        if ((p->year < year) ||
            (p->year == year && p->month < month) ||
            (p->year == year && p->month == month && p->day < day))
        {
            q = p;
            p = p->next;
        }
        else
        {
            q->next = r;
            r->next = p;
            return;
        }
    }
    q->next = r;
    r->next = p;
}

void retrieve(struct Date *list, int k)
{
    struct Date *p = list->next;
    int count = 0;

    while (p)
    {
        count++;
        if (count == k)
        {
            printf("%04d/%02d/%02d\n", p->year, p->month, p->day);
            return;
        }
        p = p->next;
    }
}

int main()
{
    int n;
    int year, month, day;
    int k;
    struct Date *list;

    list = (struct Date *)malloc(sizeof(struct Date));
    list->next = NULL;

    scanf("%d", &n);
    while (n--)
    {
        scanf("%d/%d/%d", &year, &month, &day);
        insert(list, year, month, day);
    }
    scanf("%d", &k);
    retrieve(list, k);

    return 0;
}
