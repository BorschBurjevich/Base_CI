/*G5 ДЗ 2
Заменить a на b
В файле .txt дана символьная строка не более 1000 символов. Необходимо заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и строчные. Результат записать в .txt.

Данные на входе:        Строка из маленьких и больших английских букв, знаков препинания и пробелов.
Данные на выходе:   Строка из маленьких и больших английских букв, знаков препинания и пробелов.

Пример
Данные на входе:        aabbccddABCD
Данные на выходе:   bbaaccddBACD */
#include <stdio.h>
#include <string.h>

int get_file(size_t *size,char* filename);
void change_literal(char arr_file[],size_t size);
int is_case_a(char c);
int is_case_b(char c);
int main (void)
{
    enum { BUF_SIZE = 1001,
    };
    FILE *f;
    size_t size;
    int rtrn;
    char filename[50] ={'0'};
    char read_file[BUF_SIZE] = {'0'};
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
    }
    else
    {
        printf("Can't read file: %s\n",filename);
        return -1;
    }
    change_literal(read_file,size);
    f = fopen(filename,"r+");
    if (f != NULL)
    {
        fputs(read_file,f);
    }
    else
    {
        printf("Can't write file: %s\n",filename);
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
void change_literal(char arr_file[],size_t size)
{
    int sdvig = 0x1;
    for (int cntr = 0; cntr < size; cntr++)
    {
        if (is_case_a(arr_file[cntr]))
        {
            arr_file[cntr] = arr_file[cntr] + sdvig;
            continue;
        }
        if (is_case_b(arr_file[cntr]))
        {
            arr_file[cntr] = arr_file[cntr] - sdvig;
            continue;
        }
    }
}
int is_case_a(char c)
{
    if ((c == 'a') || (c == 'A'))
    {
        return 1;
    }
    return 0;
}
int is_case_b(char c)
{
    if ((c == 'B') || (c == 'b'))
    {
        return 1;
    }
    return 0;
}
