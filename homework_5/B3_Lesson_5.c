#include <stdio.h>

int main (void)
{
    int input_a,input_b;
    int i;
    unsigned int length;
    int sum;
    printf("Enter two integer numbers A and B, A <= B:\n");
    scanf("%d%d",&input_a,&input_b);
    if (input_a < 0)   // проверка на отрицательные входные данные
    {
        length = input_a * (-1);
        length += input_b;
    }
    else if (input_b < 0)
    {
        length =  input_b * (-1);
        length += input_a;
    }
    else
    {
        length = input_b - input_a;
    }
    if (length > 200)
    {
        printf("Error in input values!\n"); // Возвращаем ошибку, если оба числа по модулю больше 100
        return 1;
    }
    sum = 0;
    for (unsigned int cntr = 0; cntr <= length; cntr++)
    {
        sum += input_a * input_a;
        input_a += 1;
    }
    printf("%d\n",sum);
    return 0;
}
