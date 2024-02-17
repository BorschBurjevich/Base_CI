/*Написать функцию и программу, демонстрирующую работу данной функции, которая ставит в
начало массива все четные элементы, а в конец – все нечетные. Не нарушайте порядок
следования чисел между собой. Строго согласно прототипу:
void sort_even_odd(int n, int a[])
Данные на входе: Функция принимает на вход целые числа
Данные на выходе: Отсортированный исходный массив
Пример №1
Данные на входе: 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
Данные на выходе: 20 18 16 14 12 10 8 6 4 2 19 17 15 13 11 9 7 5 3 1
Пример №2
Данные на входе: 1 0 1 0 1
Данные на выходе: 0 0 1 1 1*/

#include <stdio.h>
#include <string.h>
void sort_even_odd(int n, int arr[]);
int  get_input_data(int n, int arr[]);
int  isDigit(char c);
void print_result(int n, int arr[]);
int main (void)
{
    enum {BUFFER_SIZE = 1024,
        };
    int mas[BUFFER_SIZE]= {0};
    int size;

    size = get_input_data(BUFFER_SIZE,mas);
    if (size == -1)
    {
        printf ("Not enough memory allocated for input data\n");
        return -1;
    }
    sort_even_odd(size,mas);
    print_result(size,mas);
    return 0;

}
int  get_input_data(int n, int arr[])
{
    char c;
    int i = 0;
    while ((c = getchar())!='\n')
    {
        if (isDigit(c))
        {
            int number = 0;
            do
            {
                number=number*10+c-'0';
                c=getchar();
            } while (isDigit(c));
            arr[i++] = number;
            if (i > 1023)
            {
                return -1;
            }
            if(c=='\n')
            break;
        }
    }
    return i;
}
int isDigit(char c)
{
    return ((c>='0')&&(c<='9'));
}
void sort_even_odd(int n, int arr[])
{
    int temp_array[n];
    int k = 0;
    for(int i = 0; i < n; i++)
    {

        if (arr[i] % 2 == 0) {
            temp_array[k] = arr[i];
            k ++;
        }
    }

    for( int i = 0; i < n; i++)
    {
        if (arr[i] % 2 != 0)
        {
            temp_array[k] = arr[i];
            k ++;
        }
    }

    memcpy(arr, temp_array, sizeof(temp_array));
}
void print_result(int n, int arr[])
{
    for (int cntr = 0; cntr < n; cntr++)
    {
        printf("%d " ,arr[cntr]);
    }
    printf("\n");
}
