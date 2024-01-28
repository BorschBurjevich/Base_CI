/*D4 ДЗ 1
В прямом порядке
Дано натуральное число N. Выведите все его цифры по одной, в прямом порядке, разделяя их пробелами или новыми строками. Необходимо реализовать рекурсивную функцию.

void print_num(int num)

Данные на входе:        Одно целое неотрицательное число
Данные на выходе:   Все цифры числа через пробел в прямом порядке.

Пример №1
Данные на входе:        15
Данные на выходе:   1 5

Пример №2
Данные на входе:        54321
Данные на выходе:   5 4 3 2 1
*/
#include <stdio.h>
#include <inttypes.h>
void forward_poryadok(uint32_t value);
int main (void)
{
    uint32_t input_val;
    printf("Enter your integer positive value\n:");
    scanf("%d",&input_val);
    if (input_val > 0)
    {
        forward_poryadok(input_val);
    }
    else
    {
        printf("0\n");
    }
    return 0;
}
void forward_poryadok(uint32_t value)
{
    if (value > 0)
    {
        forward_poryadok(value / 10);
        printf("%d ", value % 10);
    }
}
