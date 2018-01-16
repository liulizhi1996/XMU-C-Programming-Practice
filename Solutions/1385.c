#include <stdio.h>

int main()
{
    int n, k;
    int pick_how_many;
    int turns;

    scanf("%d %d", &n, &k);
    turns = 0;
    pick_how_many = k;
    while (n > 0)
    {
        n -= pick_how_many;
        turns++;
        pick_how_many += k;
    }

    if (turns % 2 == 1)
        printf("MING!\n");
    else
        printf("QIANG!\n");
    printf("%d\n", turns);

    return 0;
}
