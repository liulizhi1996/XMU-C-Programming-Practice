#include <stdio.h>
#include <stdlib.h>

struct Good
{
    int id;
    int stock;
    int price;
    int volume;
};

void search_by_stock(struct Good *list, int n, int query)
{
    int i, found = 0;
    for (i = 0; i < n; ++i)
    {
        if (list[i].stock >= query)
        {
            found = 1;
            printf("%06d %d %d %d\n", list[i].id, list[i].stock, list[i].price, list[i].volume);
        }
    }
    if (!found)
        printf("nothing\n");
}

void search_by_price(struct Good *list, int n, int query)
{
    int i, found = 0;
    for (i = 0; i < n; ++i)
    {
        if (list[i].price >= query)
        {
            found = 1;
            printf("%06d %d %d %d\n", list[i].id, list[i].stock, list[i].price, list[i].volume);
        }
    }
    if (!found)
        printf("nothing\n");
}

void search_by_volume(struct Good *list, int n, int query)
{
    int i, found = 0;
    for (i = 0; i < n; ++i)
    {
        if (list[i].volume >= query)
        {
            found = 1;
            printf("%06d %d %d %d\n", list[i].id, list[i].stock, list[i].price, list[i].volume);
        }
    }
    if (!found)
        printf("nothing\n");
}

int main()
{
    int n, k, s, i;
    struct Good list[1005];

    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d %d %d %d", &list[i].id, &list[i].stock, &list[i].price, &list[i].volume);
    scanf("%d %d", &k, &s);
    if (k == 1)
        search_by_stock(list, n, s);
    else if (k == 2)
        search_by_price(list, n, s);
    else
        search_by_volume(list, n, s);

    return 0;
}
