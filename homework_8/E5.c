/*Сумма положительных элементов
Считать массив из 10 элементов и подсчитать сумму положительных элементов массива.

Данные на входе:        10 целых чисел через пробел
Данные на выходе:   Одно целое число - сумма положительных элементов массива

Пример №1
Данные на входе:        4 -5 3 10 -4 -6 8 -10 1 0
Данные на выходе:   26

Пример №2
Данные на входе:        1 -2 3 -4 5 -6 7 -8 9 0
Данные на выходе:   25
*/

#include <stdio.h>
#include <string.h>
unsigned int solve_sum(int* arr, const int n);
void  input_mas(int* arr, int n);

int main(void)
{
    const int size = 10;
    int mas[size];
    memset(&mas[0],0x0,sizeof(mas[0])*size);
    printf("Enter mass of 10 elements:\n");
    input_mas(mas,size);
    printf("%u",solve_sum(mas,size));
    return 0;
}

void input_mas(int* arr, const int n)
{
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
}
unsigned int solve_sum(int* arr, const int n)
{
    unsigned int result;
    result = 0;
    for(int cntr = 0; cntr < n; cntr++)
    {
        int mask;
        mask = (arr[cntr]&0x80000000) >> 31;
        if (mask != 0x1)
        {
            result += arr[cntr];
        }
    }
    return result;
}
