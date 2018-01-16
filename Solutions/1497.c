#include <stdio.h>

int main()
{
    int k, n, number, i;
    FILE *fp_in, *fp_out;

    fp_in = fopen("test.in", "r");
    fp_out = fopen("test.out", "w");

    scanf("%d", &k);
    fscanf(fp_in, "%d", &n);
    for (i = 1; i <= n; ++i)
    {
        fscanf(fp_in, "%d", &number);
        if (i != k)
            fprintf(fp_out, "%d\n", number);
    }

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}
