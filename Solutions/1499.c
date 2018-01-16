#include <stdio.h>
#include <string.h>

int main()
{
    char filename1[50] = { 0 };
    char filename2[50] = { 0 };
    char buffer1[1024] = { 0 };
    char buffer2[1024] = { 0 };
    FILE *fp1, *fp2;

    scanf("%s", filename1);
    scanf("%s", filename2);

    fp1 = fopen(filename1, "r");
    fp2 = fopen(filename2, "r");

    while (fgets(buffer1, sizeof(buffer1), fp1) && fgets(buffer2, sizeof(buffer2), fp2))
    {
        if (strcmp(buffer1, buffer2))
        {
            printf("%s", buffer1);
            printf("%s", buffer2);
        }
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}
