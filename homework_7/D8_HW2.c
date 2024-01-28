/*От A до B
Составить рекурсивную функцию, Выведите все числа от A до B включительно, в порядке возрастания, если A < B, или в порядке убывания в противном случае. 

Данные на входе:        Два целых числа через пробел.
Данные на выходе:   Последовательность целых чисел.

Пример №1
Данные на входе:        5 2
Данные на выходе:   5 4 3 2

Пример №2
Данные на входе:        2 7
Данные на выходе:   2 3 4 5 6 7
*/
#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
void poryadok(int* value_a, int* value_b, uint8_t flag);
int main (void)
{
    int input_val_a,input_val_b;
    uint8_t flag = 1;
    printf("Enter your integer positive value\n:");
    scanf("%d %d",&input_val_a,&input_val_b);
    if (input_val_a > input_val_b)
    {
        flag = 0;
        poryadok(&input_val_a, &input_val_b, flag);
    }
    else
    {
        flag = 1;
        poryadok(&input_val_a, &input_val_b, flag);
    }
    return 0;
}
void poryadok(int* value_a, int* value_b, uint8_t flag)
{
    if (flag == 0) // по убыванию
    {
        while (*value_a - *value_b >= 0)
        {
            printf("%d ",*value_a);
            *value_a -= 1;
            poryadok(value_a,value_b,flag);
        }
    }
    else    // по возрастанию
    {
        while (*value_b - *value_a >= 0)
        {
            printf("%d ",*value_a);
            *value_a += 1;
            poryadok(value_a,value_b,flag);
        }
    }
}
