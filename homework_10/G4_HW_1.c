/*По одному разу
В файле .txt даны два слова не более 100 символов каждое, разделенные одним пробелом. Найдите только те символы слов, которые встречаются в обоих словах только один раз. Напечатайте их через пробел в файл .txt в лексикографическом порядке.

Данные на входе:        Два слова из маленьких английских букв через пробел. Длинна каждого слова не больше 100 символов.
Данные на выходе:   Маленькие английские буквы через пробел.

Пример №1
Данные на входе:        hello world
Данные на выходе:   o


Данные на входе:        aabcd bcef
Данные на выходе:   b c */

#include <stdio.h>
#include <string.h>
#define DEBUG_ (1)
int get_file(size_t *size,char* filename);
void compare_string (char arr_file[],size_t size);
int main (void)
{
    enum { BUF_SIZE = 250,
    };
    FILE *f;
    size_t size;        // size of two strings with ' '
    char filename[BUF_SIZE] ={'0'};
    char read_file[BUF_SIZE] = {'0'};
    int rtrn = 0;
    rtrn = get_file(&size,filename);
    if(rtrn!=0)
    {
        return -1;
    }
    f = fopen(filename,"r");
    if (f != NULL)
    {
        fgets(read_file,size+1,f);
        compare_string(read_file,size);
        fclose(f);
        printf("\n");
    }
    else
    {
        printf("Can't read file: %s\n",filename);
        return -1;
    }
    return 0;
}
// 0 - file exist
//(-1) - file doesn't exist
int get_file(size_t *size, char* filename)
{
    FILE *f;
    printf("Input filename: ");
    scanf("%s",filename);
    f = fopen(filename,"r");
    if (f != NULL)
    {
        printf("File open correct\n");
        fseek(f,0,SEEK_END);
        *size = ftell (f);
        fclose(f);
    }
    else
    {
        printf("File doesn't exist\n");
        return -1;
    }
    return 0;
}
void compare_string (char arr_file[],size_t size)
{
    char string_1[100] = {'0'};
    char string_2[100] = {'0'};
    char same[100] = {'0'};
    size_t str1, str2;
    str1 = 0;
    str2 = 0;


    for (int cntr = 0; cntr < size; cntr++)
    {
        if(arr_file[cntr] != ' ')
        {
            str1++;
            string_1[cntr] = arr_file[cntr];
        }
        else
        {
            string_1[cntr] = '\0';
            break;
        }
    }
    int ind = 0;
    for (int cntr = str1+1; cntr < size; cntr++)
    {
        string_2[ind++] = arr_file[cntr];
        str2++;
    }
    ind = 0;
    for (int cntr = 0; cntr < str1; cntr++)
    {
        for (int j = 0; j < str2; j++)
        {
            if ((string_1[cntr] == string_2[j]) && (string_1[cntr] != string_1[j]))
            {
                same[ind++] = string_2[j];
                same[ind++] = ' ';
            }
        }
    }
    printf("%s\n",same);
}
