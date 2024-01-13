#include <stdio.h>
#define MAX_SIZE  10
int main (void)
{
    int input_num;
    int cntr,j;
    int tmp_mas[MAX_SIZE];
    printf("Enter input value:\n");
    scanf("%d",&input_num);
    if (input_num & 0x80000000) // negate input value
    {
      input_num = input_num * -1;
    }
    j = 0;
    cntr = 0;
    while (input_num > 0)  // count number 9 in input value
    {
        tmp_mas[j] = input_num % 10;
        if (tmp_mas[j] == 9)
        {
            cntr++;
        }
        input_num /= 10;
        j++;
    }
    if (cntr == 1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}
