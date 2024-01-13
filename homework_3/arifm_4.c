#include <stdio.h>
// Ввести три цисла, найти их среднее арифметическое
int main (void)
{
    int a,b,c;
    float result;
    printf("Enter three integers: \n");
    scanf("%d%d%d",&a,&b,&c);
    result = (a + b + c)/3.;
    printf("%.2f",result);
    return 0;
}
