#include <stdio.h>
#include <math.h>

int main()
{
    double x, real_value, sum_value, power;
    int t, i;

    scanf("%d", &t);
    while (t--)
    {
        scanf("%lf", &x);

        real_value = 1.0 / (1.0 - x);
        sum_value = 0;
        power = 1;
        i = 0;
        do
        {
            sum_value += power;
            if (fabs(real_value - sum_value) < 1e-6)
                break;
            power *= x;
            ++i;
        } while (1);

        printf("%d\n", i);
    }

    return 0;
}
