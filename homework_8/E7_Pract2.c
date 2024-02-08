/*E7 Практик 2
Инверсия половинок
Считать массив из 10 элементов и выполнить инверсию отдельно для 1-ой и 2-ой половин массива. Необходимо изменить считанный массив и напечатать его одним циклом.

Данные на входе:        10 целых элементов массива через пробел.
Данные на выходе:   10 целых элементов массива через пробел.

Пример №1
Данные на входе:        4 -5 3 10 -4 -6 8 -10 1 0
Данные на выходе:   -4 10 3 -5 4 0 1 -10 8 -6

Пример №2
Данные на входе:        1 2 3 4 5 6 7 8 9 10
Данные на выходе:   5 4 3 2 1 10 9 8 7 6
*/

#include <stdio.h>
void input_mas(int* arr, int n);
void revers_half(int* ptr_mas, int size, int ind);
void swap(int* ptr1, int* ptr2);
int main(void)
{
    int size = 10;
    int ind = 0;
    int mas[size];
    printf("Enter mass of 10 elements:\n");
    input_mas(&mas[0],size);
    revers_half(&mas[0],size,ind);
    ind = size/2;
    revers_half(&mas[0],size,ind);
    for(int i = 0; i < size; i++)
    {
        printf("\na[%d] = %d",i,mas[i]);
    }
    return 0;
}
void revers_half(int* ptr_mas, int size, int ind)
{
    int i,j;
    for(i = ind, j = size/2-1 + ind; i < size/4 + ind; i++, j--)
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
