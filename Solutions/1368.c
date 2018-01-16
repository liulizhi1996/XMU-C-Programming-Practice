#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100005

int main()
{
    char cipher[MAX_SIZE] = { 0 };
    char decryption[MAX_SIZE] = { 0 };
    int i;

    fgets(cipher, MAX_SIZE - 1, stdin);
    for (i = 0; cipher[i]; ++i)
    {
        if ('A' <= cipher[i] && cipher[i] <= 'Z')
            decryption[i] = (char)(25 - (cipher[i] - 'A') + 'A');
        else if ('a' <= cipher[i] && cipher[i] <= 'z')
            decryption[i] = (char)(25 - (cipher[i] - 'a') + 'a');
        else
            decryption[i] = cipher[i];
    }

    fputs(decryption, stdout);

    return 0;
}
