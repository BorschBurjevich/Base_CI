/*D3 Практик 1
В обратном порядке
Дано целое неотрицательное число N. Выведите все его цифры по одной, в обратном порядке, разделяя их пробелами или новыми строками.
Данные на входе:        Одно неотрицательное целое число
Данные на выходе:   Последовательность цифр введенного числа в обратном порядке через пробел

Пример №1
Данные на входе:        15
Данные на выходе:   5 1

Пример №2
Данные на входе:        54321
Данные на выходе:   1 2 3 4 5
*/
#include <stdio.h>
#include <inttypes.h>

uint32_t rec_poryadok(uint32_t value);
int main (void)
{
    uint32_t input_val;
    printf("Enter your integer positive value\n:");
    scanf("%d",&input_val);
    while (input_val > 0)
    {
        printf("%d\n",rec_poryadok(input_val));
        input_val = input_val / 10;
    }

    return 0;
}
uint32_t rec_poryadok(uint32_t value)
{
    uint32_t result;

    result = value % 10;
    return result;
}
