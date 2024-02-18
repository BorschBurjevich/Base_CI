/*F13
В заданном интервале
Написать функцию и программу, демонстрирующую работу данной функции, которая возвращает количество элементов на заданном отрезке [from, to] для массива. Прототип функции
 int count_between(int from, int to, int size, int a[])

Данные на входе:        Функция принимает значения концов отрезка from и to, размер массива, массив целых чисел.
Данные на выходе:   Функция возвращает целое число - количество чисел в интервале [from, to]

Пример
Данные на входе:        4 6 1 2 3 4 5 6 7 8 9 10
Данные на выходе:   3

Примечание — Интервал 4 6 числа 4 5 6 к-во 3
*/
#include <stdio.h>
void get_input_data(int *from, int *to, int *size, int arr[]);
int count_between(int from, int to, int size, int arr[]);
int main (void)
{
    enum {BUFFER_SIZE = 1024,
    };
    int arr[BUFFER_SIZE] = {0};
    int from = 0;
    int to = 0;
    int size = 0;
    int result;
    get_input_data(&from,&to,&size,arr);
    result = count_between(from,to,size,arr);
    printf("Result is: %d\n",result);

}
void get_input_data(int *from, int *to, int *size, int arr[])
{
    while (1)
    {
        printf("Enter values FROM,TO,SIZE:");
        scanf("%d %d %d",from,to,size);
        if ((*size == 0) || (*from < 0) || (*to < 0))
        {
            printf("Input values are not correct!\n");
        }
        else if ((*to - *from) > *size)
        {
            printf("Input values are not correct!\n");
        }
        else
        {
            break;
        }
    }
    printf("Enter integer elements of array:\n");
    for (int cntr = 0; cntr < *size; cntr++)
    {
      scanf("%d",&arr[cntr]);
    }
    printf("\n");
}
int count_between(int from, int to, int size, int arr[])
{
    int result = 0;
    if (to < size)  // check end of array
    {
        int size_tmp;
        size_tmp = to - from + 1;
        int tmp_array[size_tmp];
        for (int i = 0; i< size_tmp; i++)
        {
            tmp_array[i] = arr[from + i];
            printf("%d ",tmp_array[i]);
            result++;
        }
    }
    return result;
}
