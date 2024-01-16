/*
Цифры по возрастанию
Составить функцию логическую функцию, которая определяет, верно ли, что в заданном числе все цифры стоят по возрастанию. Используя данную функцию решить задачу.
int grow_up(int n)

Данные на входе:        Одно целое не отрицательное число
Данные на выходе:   YES или NO

Пример №1
Данные на входе:        258
Данные на выходе:   YES

Пример №2
Данные на входе:        528
Данные на выходе:   NO
 *
 */

#include <stdio.h>
#include <inttypes.h>
uint8_t grow_up(uint32_t value);
int main (void)
{
    uint32_t input_val;
    printf("Enter your positive number:\n");
    scanf("%d",&input_val);
    if (grow_up(input_val) == 0)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}
uint8_t grow_up(uint32_t value)
{
    const int max_size = 10;
    uint8_t result;
    int cntr,j;
    uint32_t tmp_mas[max_size];
    result = 0;
    j = 0;
    while (value > 0)
    {
        tmp_mas[j] = value % 10;
        value /= 10;
        j++;
    }
    for (cntr = 0; cntr < j - 1; cntr++)
    {
        if (tmp_mas[cntr] < tmp_mas[cntr+1])
        {
            result = 1;
            return result;
        }
    }
    return result;
}
