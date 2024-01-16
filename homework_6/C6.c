/*
Сколько зерен на доске

Когда создатель шахмат, древнеиндийский мудрец и математик Сисса бен Дахир, показал своё изобретение Правителю страны, тому так понравилась игра, что он позволил изобретателю право самому выбрать награду. Мудрец попросил у Повелителя за первую клетку шахматной доски заплатить ему одно зерно риса, за второе — два, за третье — четыре и т. д., удваивая количество зёрен на каждой следующей клетке. Помоги повелителю сосчитать сколько зерен на какой клетке лежит.

Необходимо составить функцию, которая определяет, сколько зерен попросил положить на N-ую клетку изобретатель шахмат (на 1-ую – 1 зерно, на 2-ую – 2 зерна, на 3-ю – 4 зерна, …)

Данные на входе:        Целое число от 1 до 64
Данные на выходе:   Одно целое число. Количество зерен на данной клетке.

Пример №1
Данные на входе:        3
Данные на выходе:   4

Пример №2
Данные на входе:        28
Данные на выходе:   134217728
*/
#include <stdio.h>
#include <inttypes.h>
#include <math.h>
uint64_t count_chest(uint32_t value);
int main (void)
{
    uint32_t input_val;
    printf("Enter your positive number:\n");
    scanf("%d",&input_val);
    printf("%lld",count_chest(input_val));
    return 0;
}
// основываемся на формулах геометрической прогрессии
// q = b_n/b_n - 1; q - знаменатель. Из условия задачи q = 2
// b_n = b_1 * q^(n-1)
uint64_t count_chest(uint32_t value)
{
    uint64_t b_n;
    value -= 1;
    b_n = 1.0 * powl(2.0, (long double)value);1
    return b_n;
}
