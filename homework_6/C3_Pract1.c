/*
Среднее арифметическое чисел
Написать функцию, которая возвращает среднее арифметическое двух переданных ей аргументов (параметров).
int middle(int a, int b)
Данные на входе:        Два целых неотрицательных числа
Данные на выходе:   Одно целое число

Пример №1
Данные на входе:        5 7
Данные на выходе:   6

Пример №2
Данные на входе:        10 20
Данные на выходе:   15
 *
 *
 *
*/
#include <stdio.h>
unsigned int get_middle(unsigned int a, unsigned int b);
int main (void)
{
    unsigned int input_a, input_b;
    unsigned int result;
    printf("Enter two positive numbers:\n");
    scanf("%d %d",&input_a,&input_b);
    result = get_middle(input_a,input_b);
    printf("%d\n", result);
    return 0;
}
unsigned int get_middle(unsigned int a, unsigned int b)
{
    return (a + b) >> 1;
}
