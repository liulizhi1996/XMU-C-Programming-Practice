#include <stdio.h>
#include <math.h>

int main()
{
    int k, w;
    double charge;

    scanf("%d %d", &k, &w);
    if (k == 1)
    {
        if (w <= 100)
            charge = ceil(w / 20.0) * 0.8;
        else
            charge = 5 * 0.8 + ceil((w - 100) / 100.0) * 1.2;
    }
    else
    {
        if (w <= 100)
            charge = ceil(w / 20.0) * 1.2;
        else
            charge = 5 * 1.2 + ceil((w - 100) / 100.0) * 2.0;
    }
    printf("%.2lf\n", charge);

    return 0;
}
