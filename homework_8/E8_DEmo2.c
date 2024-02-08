

/*E8 Демо 2
Инверсия каждой трети
Считать массив из 12 элементов и выполнить инверсию для каждой трети массива.

Данные на входе:        12 целых чисел через пробел
Данные на выходе:   12 целых чисел через пробел

Пример №1
Данные на входе:        4 -5 3 10 -4 -6 8 -10 1 0 5 7
Данные на выходе:   10 3 -5 4 -10 8 -6 -4 7 5 0 1

Пример №2
Данные на входе:        1 2 3 4 5 6 7 8 9 10 11 12
Данные на выходе:   4 3 2 1 8 7 6 5 12 11 10 9 */

#include <stdio.h>
void input_mas(int* arr, int n);
void revers_third(int* ptr_mas, int size, int ind);
void swap(int* ptr1, int* ptr2);
int main(void)
{
    int size = 12;
    int ind = 0;
    int mas[size];
    printf("Enter mass of 12 elements:\n");
    input_mas(&mas[0],size);
    revers_third(&mas[0],size,ind);
    ind = size/3;
    revers_third(&mas[0],size,ind);
    ind += size/3;
     revers_third(&mas[0],size,ind);
    for(int i = 0; i < size; i++)
    {
        printf("\na[%d] = %d",i,mas[i]);
    }
    return 0;
}
void revers_third(int* ptr_mas, int size, int ind)
{
    int i,j;
    for(i = ind, j = size/3-1 + ind; i < size/5 + ind; i++, j--)
    {
        swap(&ptr_mas[i], &ptr_mas[j]);
    }
}
void input_mas(int* arr,int n)
{
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
}
void swap(int* ptr1, int* ptr2)
{
    int tmp;
    tmp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tmp;
}
