#include <stdio.h>

int main()
{
    int score = 0;

    while (scanf("%d", &score) != EOF)
    {
        if (score < 0 || score > 100)
            printf("Error!\n");
        else if (0 <= score && score < 75)
            printf("level1\n");
        else if (75 <= score && score < 85)
            printf("level2\n");
        else if (85 <= score && score < 95)
            printf("level3\n");
        else
            printf("level4\n");
    }

    return 0;
}
