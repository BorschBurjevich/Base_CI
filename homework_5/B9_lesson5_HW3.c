#include <stdio.h>
#define MAX_SIZE  10
int main (void)
{
    int input_num;
    int j;
    int tmp_mas[MAX_SIZE];
    char flag;
    printf("Enter input value:\n");
    scanf("%d",&input_num);
    if (input_num & 0x80000000) // negate input value
    {
      input_num = input_num * -1;
    }
    j = 0;
    flag = 0;
    while (input_num > 0)
    {
        tmp_mas[j] = input_num % 10;
        input_num /= 10;
        if (tmp_mas[j] % 2 != 0)
        {
            flag = 1;
        }
        j++;
    }
    if (flag == 1)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
    }
    return 0;
}
