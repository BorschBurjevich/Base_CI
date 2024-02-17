/*F9
Поменять местами
Написать функцию и программу, демонстрирующую работу данной функции, которая в массиве находит максимальный из отрицательных элементов и меняет его местами с последним элементом массива. Гарантируется, что в массиве только один такой элемент или же такой элемент отсутствует. Если отрицательных элементов нет - массив не менять.

Прототип функции:
void swap_negmax_last(int size, int a[])

Данные на входе:        Функция принимает на вход размер массива и указатель на начало массива. Массив состоит из целых чисел.

Пример
Данные на входе:        1 -2 -3 -4 5 6 7 8 9 10
Данные на выходе:   1 10 -3 -4 5 6 7 8 9 -2 */
#include <stdio.h>
void swap_negmax_last(int size, int arr[]);
int main (void)
{
    enum  {BUFFER_SIZE = 1024,
    };

    int mas_input[BUFFER_SIZE] = {0};
    int size;
    printf("Size of data: \n");
    scanf("%d",&size);
    printf("Enter element of input data:\n");
    for (int cntr = 0; cntr < size; cntr++)
    {
         scanf("%d",&mas_input[cntr]);
    }
    printf("\n");
    swap_negmax_last(size,mas_input);
    for (int cntr = 0; cntr < size; cntr++)
    {
        printf("%d ",mas_input[cntr]);
    }
     printf("\n");
    return 0;
}
void swap_negmax_last(int size, int arr[])
{
    int tmp;
    int tmp2;
    int flag_neg = 0;
    tmp = 0;
    tmp2 = 0;
    for (int cntr = 0; cntr < size; cntr++)
    {
        if ((flag_neg == 1) && (arr[cntr] < 0))// neg value was saved
        {
            if ((arr[cntr] *(-1)) < (tmp * -1))
            {
                tmp = arr[cntr]; // new max neg element
                tmp2 = cntr;     // save index
            }
        }
        else
        {
            if (arr[cntr] < 0)
            {
                tmp = arr[cntr];
                tmp2 = cntr;    // save index
                flag_neg = 1;
            }
        }
    }
    if (flag_neg == 1)
    {
        int swap;
        swap = arr[size-1];
        arr[size-1] = tmp;
        arr[tmp2] = swap;
        flag_neg = 0;
    }
}
