#include <stdio.h>

int main()
{
    char filename1[50] = { 0 };
    char filename2[50] = { 0 };
    char filename3[50] = { 0 };
    int number1, number2;
    FILE *fp1, *fp2, *fp3;

    scanf("%s", filename1);
    scanf("%s", filename2);
    scanf("%s", filename3);

    fp1 = fopen(filename1, "r");
    fp2 = fopen(filename2, "r");
    fp3 = fopen(filename3, "w");

    fscanf(fp1, "%d", &number1);
    fscanf(fp2, "%d", &number2);
    while (!feof(fp1) && !feof(fp2))
    {
        if (number1 <= number2)
        {
            fprintf(fp3, "%d\n", number1);
            fscanf(fp1, "%d", &number1);
        }
        else
        {
            fprintf(fp3, "%d\n", number2);
            fscanf(fp2, "%d", &number2);
        }
    }
    while (!feof(fp1))
    {
        fprintf(fp3, "%d\n", number1);
        fscanf(fp1, "%d", &number1);
    }
    while (!feof(fp2))
    {
        fprintf(fp3, "%d\n", number2);
        fscanf(fp2, "%d", &number2);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    return 0;
}
