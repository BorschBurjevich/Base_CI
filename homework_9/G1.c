/*G3 Практ 1
Последний номер символа
В файле .txt дана строка из 1000 символов. Показать номера символов, совпадающих с последним символом строки. Результат записать в файл .txt

Данные на входе:    Строка не более 1000 символов
Данные на выходе:   Целые числа через пробел - номера символа, который совпадает с последним символом строки.

Пример
Данные на входе:        aabbcdb
Данные на выходе:   2 3 */

#include <stdio.h>
#include <string.h>
#define DEBUG_ (0)
int get_file(size_t *size,char* filename);
int main (void)
{
    FILE *f;
    size_t size;
    char filename[100] ={0};
    char read_file[1000] = {0};
    int rtrn = 0;
    rtrn = get_file(&size,filename);
    if(rtrn!=0)
    {
        return -1;
    }
    f = fopen(filename,"r");
    if (f != NULL)
    {
        int tmp = 0;
        int cntr;
        char last_symbol;
        fgets(read_file,size+1,f);
        last_symbol = read_file[size-1];
        fclose(f);
#if DEBUG_
        printf("Read_String is: %s\n", read_file);
        printf("Las symbol is : %c\n",last_symbol);
#endif
        for(cntr = 0; cntr < size - 1; cntr++)
        {
            if (read_file[cntr] == last_symbol)
            {
                tmp = cntr;
                printf("%d ",tmp);
            }
        }
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
#if DEBUG_
        printf("File sizeof '%s' - %llu bytes.\n",filename, *size);
#endif
    }
    else
    {
        printf("File doesn't exist\n");
        return -1;
    }
    return 0;
}

