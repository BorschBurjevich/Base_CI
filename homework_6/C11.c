/*
 * C11 ДЗ
НОД
Составить функцию, которая определяет наибольший общий делитель двух натуральных и привести пример ее использования.
int nod(int a, int b)
Данные на входе:        Два целых положительных числа
Данные на выходе:   Одно целое число - наибольший общий делитель.

Пример №1
Данные на входе:        14 21
Данные на выходе:   7
*/
#include <stdio.h>
#include <inttypes.h>
uint32_t nod(uint32_t input_a,uint32_t input_b);
int main (void)
{
    uint32_t input_a,input_b;
    printf("Enter your positive numbers:\n");
    scanf("%d %d",&input_a, &input_b);
    printf("%d",nod(input_a,input_b));
    return 0;
}

uint32_t nod(uint32_t input_a,uint32_t input_b)
{
    uint32_t result;
    if (input_a > input_b)
    {
        uint32_t tmp,tmp2;
        tmp = input_a % input_b;
        if (tmp == 0)
        {
            result = input_b;
        }
        else
        {
            tmp2 = input_b;
            do
            {
                tmp2 = tmp2 % tmp;
            }while(tmp2 != 0);
            result = tmp;
        }
    }
    else if (input_b > input_a)
    {
        uint32_t tmp,tmp2;
        tmp = input_b % input_a;
        if (tmp == 0)
        {
            result = input_a;
        }
        else
        {
            tmp2 = input_a;
            do
            {
                tmp2 = tmp2 % tmp;
            }while(tmp2 != 0);
            result = tmp;
        }
    }
    else // a == b
    {
       result = input_a;
    }
    return result;
}
