/*Цифры в строке
Написать функцию и программу, демонстрирующую работу данной функции.
Вывести в порядке возрастания цифры, входящие в строку. Цифра - количество. Функция должно строго соответствовать прототипу:

void print_digit(char s[])

Данные на входе:        Строка из английских букв, пробелов, знаков препинания и цифр
Данные на выходе:   Функция должна принимать на вход строку и выводить на печать по формату: Цифра пробел количество.

Пример
Данные на входе:        Hello123 world77.
Данные на выходе:   1 1 2 1 3 1 7 2*/
#include <stdio.h>
#include <string.h>
void get_string(char mas_ch[]);
void  print_digit(char arr[]);
int  isDigit(char c);
int main(void)
{
    enum { SIZE_MAS = 2048,
    };
    char mas_input[SIZE_MAS] = {0};
    get_string(mas_input);
    print_digit(mas_input);
    return 0;
}
void get_string(char mas_ch[])
{
    printf("Input your string:\n");
    scanf("%[^\n]",mas_ch);
}
void  print_digit(char arr[])
{
    int tmp_mas[2048] = {0};
    int i =0;
    int cntr;

    cntr = strlen(arr);
    for (i = 0; i < cntr; i++)
    {
        if (arr[i] >= '0' && arr[i] <= '9')
        {
            tmp_mas[arr[i] - '0']++;
        }
    }
    for (int j = 0; j < cntr; j++)
    {
        if (tmp_mas[j] > 0)
        {
            printf("%d %d ", j, tmp_mas[j]);
        }
    }
    printf("\n");
}
