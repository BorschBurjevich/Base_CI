/*E1 ДЗ 1
Среднее арифметическое чисел
Ввести c клавиатуры массив из 5 элементов, найти среднее арифметическое всех элементов массива.

Данные на входе:        5 целых ненулевых чисел через пробел
Данные на выходе:   Одно число в формате "%.3f"

Пример №1
Данные на входе:        4 15 3 10 14
Данные на выходе:   9.200

Пример №2
Данные на входе:        1 2 3 4 5
Данные на выходе:   3.000 */
#include <stdio.h>
float solve_arifm(int* arr, const int n);
void  input_mas(int* arr, int n);

int main(void)
{
    const int size = 5;
    int mas[size] = {};
    printf("Enter mass of 5 elements:\n");
    input_mas(mas,size);
    printf("%.3f",solve_arifm(mas,size));
    return 0;
}

void input_mas(int* arr, const int n)
{
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
}
float solve_arifm(int* arr, const int n)
{
    float result;
    result = 0.0;
    for(int cntr = 0; cntr < n; cntr++)
    {
        result += arr[cntr];
    }
    result = (float)result / n;
    return result;
}
