/*
Сумма от 1 до N
Составить функцию, которая определяет сумму всех чисел от 1 до N и привести пример ее использования.

Пример №1
Данные на входе:        Одно целое положительное число N
Данные на выходе:   Целое число - сумма чисел от 1 до N

Пример №2
Данные на входе:        100
Данные на выходе:   5050
*
*
*
*
*/

#include <stdio.h>
#include <inttypes.h>
uint64_t sum_n(uint32_t last_val);
int main (void)
{
    uint32_t input_val;
    uint64_t result_sum;
    printf("Enter your positive number:\n");
    scanf("%d",&input_val);
    result_sum = sum_n(input_val);
    printf("%lld\n",result_sum);
    return 0;
}

uint64_t sum_n(uint32_t last_val)
{
    uint64_t result;
    result = 0;
    for (int cntr = 1; cntr <= last_val; cntr++)
    {
        result += cntr;
    }
    return result;
}
