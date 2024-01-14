#include <stdio.h>
// На вход подаётся ппроизвольное трёхзначное число.
// Нужно напечатать произведение цифр.
int main (void)
{
    int input,output,units,tens,hund;
    printf("Enter integer positive number: \n");
    scanf("%d",&input);
    units = input % 10;
    tens  = (input % 100 - units) / 10;
    hund  = input / 100;
    output = hund * tens * units;
    printf("%d",output);
    return 0;
}
