#include <stdio.h>

int main (void)
{
    unsigned int input;
    unsigned int ordinal_number;
    printf("Enter your positive number:\n");
    scanf("%d",&input);
    ordinal_number = input / 100;
    if (ordinal_number >= 1 && ordinal_number < 9)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}
