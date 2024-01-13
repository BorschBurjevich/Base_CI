#include <stdio.h>
#define MAX_SIZE  10
int main (void)
{
    int input_num;
    int cntr,j;
    int tmp_mas[MAX_SIZE];
    char flag;
    printf("Enter input value:\n");
    scanf("%d",&input_num);
    if (input_num & 0x80000000) // negate input value
    {
      input_num = input_num * -1;
    }
    j = 0;
    while (input_num > 0)
    {
        tmp_mas[j] = input_num % 10;
        input_num /= 10;
        j++;
    }
    // search two same numbers
    flag = 0;
    for (cntr = 0; cntr < j - 1; cntr++)
    {
        if (tmp_mas[cntr] == tmp_mas[cntr+1])
        {
            printf("YES\n");
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
       printf("NO\n");
    }
    return 0;
}
