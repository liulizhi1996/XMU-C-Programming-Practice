#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int number;
    struct Node *next;
};
struct Node *head, *tail;

void create(int n)
{
    struct Node *p;
    int i;

    head = (struct Node *)malloc(sizeof(struct Node));
    head->number = 1;
    head->next = head;
    tail = head;
    for (i = 2; i <= n; ++i)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->number = i;
        p->next = head;
        tail->next = p;
        tail = p;
    }
}

void joseph(int n, int m)
{
    struct Node *p, *q;
    int i;

    p = head;
    q = tail;
    while (n--)
    {
        for (i = 0; i < m-1; ++i)
        {
            q = p;
            p = p->next;
        }
        printf("%d ", p->number);
        q->next = p->next;
        free(p);
        p = q->next;
    }
    printf("\n");
}

int main()
{
    int n, m;

    scanf("%d %d", &n, &m);
    create(n);
    joseph(n, m);

    return 0;
}
