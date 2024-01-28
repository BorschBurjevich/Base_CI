/*Все нечетные
Дана последовательность целых чисел через пробел, завершающаяся числом 0. Выведите все нечетные числа из этой последовательности, сохраняя их порядок.
Данные на входе:        Последовательность ненулевых целых чисел. В конце число 0.
Данные на выходе:   Введенная последовательность, кроме четных чисел в том же порядке. Число 0 не выводить.

Пример
Данные на входе:        12 13 173 28 19 0
Данные на выходе:   13 173 19
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
void split_numbers(char *buff, int size);
int main(void) {
    int j;
    char buff_input[MAX_SIZE] = {0};
    printf("Enter your integer positive values\n:");
    j = 0;
    for (int cntr = 0; cntr < MAX_SIZE; cntr++)
    {
        buff_input[j] = getchar();
        if (buff_input[j] == '0')
        {
            break;
        }
        j++;
    }
    split_numbers(&buff_input[0], j);

    return 0;
}
void split_numbers(char *buff, int size) {
    long int numbers[MAX_SIZE] = {0}; // преобразованный массив чисел
    int i;
    char delimiters[] = " ";          // разделитель пробел
    char *token;
    // Получение первой подстроки
    token = strtok(buff, delimiters);
    i = 0;

    while (token != NULL)
    {
        numbers[i] = atoi(token);
        i++;
        token = strtok(NULL, delimiters);
    }
    for (int cntr = 0; cntr < i; cntr++)
    {
        if (numbers[cntr] % 2 != 0)
        {
            printf("%ld ",numbers[cntr]);
        }
    }
}


