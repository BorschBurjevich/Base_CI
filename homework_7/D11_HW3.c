/*Количество 1
Дано натуральное число N. Посчитать количество «1» в двоичной записи числа.
Данные на входе:        Натуральное число
Данные на выходе:   Целое число - количество единиц в двоичной записи числа.

Пример №1
Данные на входе:        5
Данные на выходе:   2

Пример №2
Данные на входе:        255
Данные на выходе:   8
*/
// выделим 4 байта под число

#include <stdio.h>
#include <inttypes.h>
uint32_t search_numb(uint32_t value_a);
int main (void)
{
    int input_val;
    printf("Enter your integer positive value\n:");
    scanf("%d",&input_val);
    printf("%d\n",search_numb(input_val));

    return 0;
}
uint32_t search_numb(uint32_t value_a)
{
    const int num_bit = 32;
    uint32_t search = 0;
    for (int cntr = 0; cntr < num_bit; cntr++)
    {
        if ((value_a & 0x1) == 1)
        {
            search++;
        }
        value_a >>= 1;
    }
    return search;
}

