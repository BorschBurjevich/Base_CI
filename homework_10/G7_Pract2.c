/*G7 Практ 2
Количество букв
В файле .txt считать символьную строку, не более 10 000 символов. Посчитать количество строчных (маленьких) и прописных (больших) букв в введенной строке. Учитывать только английские буквы. Результат записать в файл .txt.

Данные на входе:        Строка состоящая из английских букв, цифр, пробелов и знаков препинания.
Данные на выходе:   Два целых числа. Количество строчных букв и количество заглавных букв.

Пример №1
Данные на входе:        aabbAB
Данные на выходе:   4 2

Пример №2
Данные на входе:        HELLO WORLD
Данные на выходе:   0 10
*/

#include <stdio.h>
#include <string.h>

int get_file(size_t *size,char* filename);
void count_literal(char arr_file[],size_t size,int out[]);
int is_lower_case(char c);
int is_upper_case(char c);
int main (void)
{
    enum { BUF_SIZE = 10001,
    };
    FILE *f;
    size_t size;
    int rtrn;
    char filename[50] ={'0'};
    char read_file[BUF_SIZE] = {'0'};
    int out[2] = {0};
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
    count_literal(read_file,size,out);
    f = fopen(filename,"w+");
    if (f != NULL)
    {

        fprintf(f,"%d ",out[0]);
        fprintf(f,"%d",out[1]);
        fclose(f);
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
/*out[0] - count of lower_case
out[1] - count of upper_cases
*/
void count_literal(char arr_file[],size_t size,int out[])
{
    int flag_lower;
    int flag_upper;
    int cntr_lower;
    int cntr_upper;
    flag_lower = 0;
    flag_upper = 0;
    cntr_lower = 0;
    cntr_upper = 0;
    for (int cntr = 0; cntr < size; cntr++)
    {
        if (is_lower_case(arr_file[cntr]))
        {
            flag_lower = 1;
            cntr_lower++;
            out[0] = cntr_lower;
        }

        if (is_upper_case(arr_file[cntr]))
        {
            flag_upper = 1;
            cntr_upper++;
            out[1] = cntr_upper;
        }
    }
    if (flag_lower == 0)
    {
        out[0] = 0;
    }
    if (flag_upper == 0)
    {
        out[1] = 0;
    }
}
int is_lower_case(char c)
{
    if ((c >= 'a') && (c <= 'z'))
    {
        return 1;
    }
    return 0;
}
int is_upper_case(char c)
{
    if ((c >= 'A') && (c <= 'Z'))
    {
        return 1;
    }
    return 0;
}
