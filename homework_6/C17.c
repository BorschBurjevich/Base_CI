/*Сумма цифр равна произведению

Составить логическую функцию, которая определяет, верно ли, что в данном числе сумма цифр равна произведению.

int is_happy_number(int n)

Данные на входе:        Целое не отрицательное число
Данные на выходе:   YES или NO

Пример №1
Данные на входе:        123
Данные на выходе:   YES

Пример №2
Данные на входе:        528
Данные на выходе:   NO
*/

#include <stdio.h>
#include <inttypes.h>
uint8_t happy_number(uint32_t value);
int main (void)
{
    uint32_t input_val;
    printf("Enter your positive number:\n");
    scanf("%d",&input_val);
    if (happy_number(input_val) == 0)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}
uint8_t happy_number(uint32_t value)
{
    uint8_t result;
    uint32_t sum, multy;
    result = 0;
    sum = 0;
    multy = 1;
    while (value > 0)
    {
        sum += value % 10;
        multy *= value % 10;
        value /= 10;
    }
    if (sum != multy)
    {
        result = 1;
        return result;
    }
    return result;
}
