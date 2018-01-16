#include <stdio.h>
#include <string.h>

struct Student
{
    char id[20];
    int chinese;
    int math;
    int english;
    int physics;
    int chemistry;
    int biology;
    int index;
};

int cmp_chinese(struct Student a, struct Student b)
{
    return (a.chinese < b.chinese) || ((a.chinese == b.chinese) && (strcmp(a.id, b.id) > 0));
}

int cmp_math(struct Student a, struct Student b)
{
    return (a.math < b.math) || ((a.math == b.math) && (strcmp(a.id, b.id) > 0));
}

int cmp_english(struct Student a, struct Student b)
{
    return (a.english < b.english) || ((a.english == b.english) && (strcmp(a.id, b.id) > 0));
}

int cmp_physics(struct Student a, struct Student b)
{
    return (a.physics < b.physics) || ((a.physics == b.physics) && (strcmp(a.id, b.id) > 0));
}

int cmp_chemistry(struct Student a, struct Student b)
{
    return (a.chemistry < b.chemistry) || ((a.chemistry == b.chemistry) && (strcmp(a.id, b.id) > 0));
}

int cmp_biology(struct Student a, struct Student b)
{
    return (a.biology < b.biology) || ((a.biology == b.biology) && (strcmp(a.id, b.id) > 0));
}

int partition(struct Student *array, int low, int high, int (*cmp)(struct Student, struct Student))
{
    int mid = (low + high) / 2;
    array[0] = array[mid];
    array[mid] = array[low];

    while (low < high)
    {
        while (low < high && (*cmp)(array[high], array[0]))
            --high;
        array[low] = array[high];
        while (low < high && !(*cmp)(array[low], array[0]))
            ++low;
        array[high] = array[low];
    }
    array[low] = array[0];

    return low;
}

void quicksort(struct Student *array, int low, int high, int (*cmp)(struct Student, struct Student))
{
    if (low >= high)
        return;
    int pivot = partition(array, low, high, cmp);
    quicksort(array, low, pivot-1, cmp);
    quicksort(array, pivot+1, high, cmp);
}

int main()
{
    int n, k, i;
    struct Student stu[1005];
    int (*cmp)(struct Student, struct Student);

    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
    {
        scanf("%s %d %d %d %d %d %d", stu[i].id, &stu[i].chinese, &stu[i].math, &stu[i].english, &stu[i].physics,
              &stu[i].chemistry, &stu[i].biology);
        stu[i].index = i;
    }
    scanf("%d", &k);

    switch (k)
    {
        case 1: cmp = cmp_chinese; break;
        case 2: cmp = cmp_math; break;
        case 3: cmp = cmp_english; break;
        case 4: cmp = cmp_physics; break;
        case 5: cmp = cmp_chemistry; break;
        case 6: cmp = cmp_biology; break;
        default: break;
    }

    quicksort(stu, 1, n, cmp);
    for (i = 1; i <= n; ++i)
        printf("%d\n", stu[i].index);

    return 0;
}
