#include <stdio.h>
#define MAX_SIZE  10
int main (void)
{
    unsigned int input_num,max_output,min_output;
    unsigned int cntr,j;
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
    max_output = tmp_mas[0];
    min_output = tmp_mas[0];
    for (cntr = 0; cntr < j - 1; cntr++)
    {
        if (tmp_mas[cntr + 1] > max_output)
        {
            max_output = tmp_mas[cntr + 1];
        }
        if (tmp_mas[cntr + 1] < min_output)
        {
            min_output = tmp_mas[cntr + 1];
        }
    }
    printf("%d %d\n",min_output,max_output);
    return 0;
}

