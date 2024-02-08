/*Среднее арифметическое массива
Считать массив из 12 элементов и подсчитать среднее арифметическое элементов массива.

Данные на входе         12 целых чисел через пробел
Данные на выходе    Среднее арифметическое в формате %.2f

Пример №1
Данные на входе         4 -5 3 10 -4 -6 8 -10 1 0 5 7
Данные на выходе    1.08

Пример №2
Данные на входе         1 2 3 4 5 6 7 8 9 10 11 12
Данные на выходе    6.50
*/

#include <stdio.h>
float solve_arifm(int* arr, const int n);
void  input_mas(int* arr, int n);

int main(void)
{
    const int size = 12;
    int mas[size] = {};
    printf("Enter mass of 12 elements:\n");
    input_mas(mas,size);
    printf("%.2f",solve_arifm(mas,size));
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
