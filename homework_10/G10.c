/*G10
Самое длинное слово
В файле .txt дана строка слов, разделенных пробелами. Найти самое длинное слово и вывести его в файл .txt. Случай, когда самых длинных слов может быть несколько, не обрабатывать.

Данные на входе:        Строка из английских букв и пробелов. Не более 1000 символов.
Данные на выходе:   Одно слово из английских букв.

Пример
Данные на входе:        Hello beautiful world
Данные на выходе:   beautiful
*/
#include <stdio.h>
#include <string.h>
int get_file(size_t *size,char* filename);
void compare_string_write_max(char arr_file[],size_t size,char name[]);
int main (void)
{
    enum { BUF_SIZE = 10001,
    };
    FILE *f;
    size_t size;
    char filename[50] ={'0'};
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
        fclose(f);
        compare_string_write_max(read_file,size,filename);
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
        *size = ftell(f);
        fclose(f);
    }
    else
    {
        printf("File: %s doesn't exist\n",filename);
        return -1;
    }
    return 0;
}
void compare_string_write_max(char arr_file[],size_t size,char name[])
{
    FILE *f;
    char string_1[1000] = {'0'};
    char string_2[1000] = {'0'};
    char string_3[1000] = {'0'};
    int ind;
    size_t str1,str2,str3;
    str1 = 0;
    str2 = 0;
    str3 = 0;
    ind  = 0;
    for (int cntr = 0; cntr < size; cntr++)
    {
        if(arr_file[cntr] != ' ')
        {
            string_1[cntr] = arr_file[cntr];
        }
        else
        {
            string_1[cntr] = '\0';
            break;
        }
    }
    str1 = strlen(string_1);
    ind  = 0;
    for (int cntr = str1+1; cntr < size; cntr++)
    {
        if(arr_file[cntr] != ' ')
        {
            string_2[ind++] = arr_file[cntr];
        }
        else
        {
            string_2[cntr] = '\0';
            break;
        }
    }
    str2 = strlen(string_2);
    ind  = 0;
    for (int cntr = str1+str2+2; cntr < size; cntr++)
    {
        string_3[ind++] = arr_file[cntr];
    }
    str3 = strlen(string_3);

    int max = str1;
    f = fopen(name,"w+");
    if (f == NULL)
    {
       printf("Cant read and write to %s\n",name);
    }
    else
    {
        if (str2 > str3)
        {
            if (str2 > max)
            {
                max = str2;
                printf("Max string is: %s\n",string_2);
                fprintf(f,"%s",string_2);
            }
        }
        else if (str3 > str2)
        {
            if (str3 > max)
            {
                max = str3;
                printf("Max string is: %s\n",string_3);
                fprintf(f,"%s",string_3);
            }
        }
        else
        {
            printf("Max string is: %s\n",string_1);
            fprintf(f,"%s",string_1);
        }
        fclose(f);
    }
}
