#include <stdio.h>

int main()
{
    double a, b;
    char operator;

    scanf("%lf %c %lf =", &a, &operator, &b);
    switch (operator)
    {
        case '+': printf("%.4lf\n", a + b); break;
        case '-': printf("%.4lf\n", a - b); break;
        case '*': printf("%.4lf\n", a * b); break;
        case '/': if (b == 0) printf("Error!\n"); else printf("%.4lf\n", a / b); break;
        default: break;
    }

    return 0;
}
