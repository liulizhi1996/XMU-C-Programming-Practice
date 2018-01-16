#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int id;
    char course_name[20];
    int score;
};

int cmp(const void *p, const void *q)
{
    struct Student a = *(struct Student *)p;
    struct Student b = *(struct Student *)q;
    return (a.id > b.id) || (a.id == b.id && strcmp(a.course_name, b.course_name) > 0);
}

int main()
{
    int n, m, i, j;
    char filename[50] = { 0 };
    char course_name[10][20] = { 0 };
    FILE *fp;
    struct Student list[50];

    scanf("%d %d", &n, &m);
    scanf("%s", filename);
    for (i = 1; i <= m; ++i)
        scanf("%s", course_name[i]);
    for (i = 1; i <= n*m; ++i)
        scanf("%d %s %d", &list[i].id, list[i].course_name, &list[i].score);
    qsort(list+1, n*m, sizeof(struct Student), cmp);

    fp = fopen(filename, "w");
    for (i = 1; i <= n; ++i)
    {
        fprintf(fp, "%d\n", i);
        for (j = 1; j <= m; ++j)
            fprintf(fp, "%s %d\n", list[m * (i-1) + j].course_name, list[m * (i-1) + j].score);
        fprintf(fp, "\n");
    }
    fclose(fp);

    return 0;
}
