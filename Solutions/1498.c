#include <stdio.h>

int main()
{
    char src[50] = { 0 };
    char dest[50] = { 0 };
    char buffer[1024] = { 0 };
    FILE *fp_src, *fp_dest;

    scanf("%s", src);
    scanf("%s", dest);

    fp_src = fopen(src, "r");
    fp_dest = fopen(dest, "w");

    while (fgets(buffer, sizeof(buffer), fp_src))
    {
        fputs(buffer, fp_dest);
    }

    fclose(fp_src);
    fclose(fp_dest);

    return 0;
}
