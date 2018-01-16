#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_palindrome(long long int number)
{
    char string[30] = { 0 };
    sprintf(string, "%lld", number);
    int len = (int)strlen(string);
    int i, j;
    for (i = 0, j = len-1; i < j; ++i, --j)
    {
        if (string[i] != string[j])
            return 0;
    }
    return 1;
}

long long int reverse(long long int number)
{
    char string[30] = { 0 };
    sprintf(string, "%lld", number);
    int len = (int)strlen(string);
    int i, j;
    for (i = 0, j = len-1; i < j; ++i, --j)
    {
        char temp = string[i];
        string[i] = string[j];
        string[j] = temp;
    }
    return atoll(string);
}

int main()
{
    long long int n, reversed, sum;

    scanf("%lld", &n);
    do {
        reversed = reverse(n);
        sum = n + reversed;
        printf("%lld+%lld=%lld\n", n, reversed, sum);
        n = sum;
    } while (!is_palindrome(n));

    return 0;
}
