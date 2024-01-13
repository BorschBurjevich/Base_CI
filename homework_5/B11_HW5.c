#include <stdio.h>
#define MAX_SIZE  10
int main (void)
{
    unsigned int input_num,output_num;
    unsigned int cntr,j,i,position;
    unsigned int tmp_mas[MAX_SIZE];
    printf("Enter input positive value:\n");
    scanf("%d",&input_num);
    j = 0;
    while (input_num > 0)
    {
        tmp_mas[j] = input_num % 10;
        input_num /= 10;
        j++;
    }
    output_num = 0;
    position = 10;
    i = 0;
    for (cntr = 0; cntr < j - 2; cntr++)
    {
        position = position * 10;
    }
    for (cntr = j; cntr > 0; cntr--)
    {
        output_num += tmp_mas[i] * position;
        position = position / 10;
        i++;
    }
    printf("%d\n",output_num);
    return 0;
}

