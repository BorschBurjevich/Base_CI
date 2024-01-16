/*
Факториал
Составить функцию вычисления N!. Использовать ее при вычислении факториала
int factorial(int n)

Данные на входе:        Целое положительное число не больше 20
Данные на выходе:   Целое положительное число

Пример №1
Данные на входе:        5
Данные на выходе:   120

 */
#include <stdio.h>
#include <inttypes.h>
uint64_t factorial(uint32_t last_val);
int main (void)
{
    uint32_t input_val;
    printf("Enter your positive number:\n");
    scanf("%d",&input_val);
    if (input_val > 20)
    {
      printf("Error in input values!\n");
      return -1;
    }
    printf("%lld\n",factorial(input_val));
    return 0;
}

// N! = 1*2*...*N
uint64_t factorial(uint32_t last_val)
{
    uint64_t result;
    result = 1;
    for (int cntr = 1; cntr <= last_val; cntr++)
    {
        result *= cntr;
    }
    return result;
}
