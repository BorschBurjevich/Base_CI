/*F5 ДЗ 3
Максимум в массиве
Написать функцию и программу, демонстрирующую работу данной функции, которая находит максимальный элемент в массиве.

Прототип функции:
int find_max_array(int size, int a[])

Данные на входе:        Массив состоящий из целых чисел. Первый аргумент, размер массива, второй аргумент адрес нулевого элемента.
Данные на выходе:   Одно целое число

Пример №1
Данные на входе:        773 307 371 548 531 765 402 27 573 591 217 859 662 493 173 174 125 591 324 231 130 394 573 65 570 258 343 3 586 14 785 296 140 726 598 262 807 794 510 465 66 895 182 218 302 34 205 252 687 660 952 737 2 32 310 680 36 139 346 139 489 217 767 544 158 774 883 154 802 136 569 377 867 423 224 176 118 660 513 734 45 978 983 749 909 601 270 147 433 737 789 304 842 769 815 503 190 399 3.
Данные на выходе:   983
*/

#include <stdio.h>
int  get_input_data(int n, int arr[]);
int isDigit(char c);
int find_max_array(int size, int arr[]);
int main (void)
{
    enum  {BUFFER_SIZE = 1024,
    };
    int size;
    int mas[BUFFER_SIZE] = {0};
    int max_element;
    size = get_input_data(BUFFER_SIZE,mas);
    if (size == -1)
    {
        printf ("Not enough memory allocated for input mas\n");
        return -1;
    }
    max_element = find_max_array(size, mas);
    printf("Maximum is : %d\n",max_element);
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
int find_max_array(int size, int arr[])
{
    int max_el;
    max_el = arr[0];
    for (int cntr = 0; cntr < size; cntr++)
    {
        if (arr[cntr] > max_el)
        {
           max_el = arr[cntr];
        }
    }
    return max_el;
}
