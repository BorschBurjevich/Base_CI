#include <stdio.h>
// На вход подаётся целое положительное трёхзначное число.
// Нужно напечатать максимальную  цифру .
int main (void)
{
    int input,max,units,tens,hund;
    printf("Enter integer positive number: \n");
    scanf("%d",&input);
    units = input % 10;
    tens  = (input % 100 - units) / 10;
    hund  = input / 100;
    max = units > tens ? units : tens;
    max = max > hund ? max : hund;
    printf("%d",max);
    return 0;
}
