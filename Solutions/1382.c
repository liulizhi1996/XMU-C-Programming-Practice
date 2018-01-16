#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char *word;
    struct Node *next;
};

int insert(struct Node *vocabulary, char *word)
{
    struct Node *p, *q, *r;
    int cmp;

    p = vocabulary->next;
    q = vocabulary;
    while (p)
    {
        cmp = strcmp(p->word, word);
        if (cmp == 0)
            return 0;
        else if (cmp < 0)
        {
            q = p;
            p = p->next;
        }
        else
        {
            r = (struct Node *)malloc(sizeof(struct Node));
            r->word = (char *)malloc(sizeof(char) * 15);
            strcpy(r->word, word);
            q->next = r;
            r->next = p;
            return 1;
        }
    }
    r = (struct Node *)malloc(sizeof(struct Node));
    r->word = (char *)malloc(sizeof(char) * 15);
    strcpy(r->word, word);
    q->next = r;
    r->next = p;
    return 1;
}

int main()
{
    int n, count = 0, i;
    char word[15] = { 0 };
    struct Node *vocabulary;

    vocabulary = (struct Node *)malloc(sizeof(struct Node));
    vocabulary->next = NULL;

    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        scanf("%s", word);
        count += insert(vocabulary, word);
    }
    printf("%d\n", count);

    return 0;
}
