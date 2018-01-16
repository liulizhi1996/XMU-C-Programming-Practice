#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int element;
    struct Node *next;
};

int main()
{
    int key, has_even;
    struct Node *list, *p, *q;

    list = (struct Node *)malloc(sizeof(struct Node));
    list->next = NULL;
    q = list;

    while (scanf("%d", &key) && key != 0)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->element = key;
        p->next = NULL;
        q->next = p;
        q = p;
    }

    p = list->next;
    has_even = 0;
    while (p)
    {
        if (p->element % 2 == 0)
        {
            has_even = 1;
            printf("%d ", p->element);
        }
        p = p->next;
    }
    if (!has_even)
        printf("Empty");
    printf("\n");

    return 0;
}
