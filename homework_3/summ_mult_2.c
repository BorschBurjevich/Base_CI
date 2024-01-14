#include <stdio.h>
/// Ввести три числа, найти их сумму и произведение
int main (void)
{
    int a,b,c,sum,mult;
    printf("Enter three integers: \n");
    scanf("%d%d%d",&a,&b,&c);
    sum = a + b + c;
    mult = a * b * c;
    printf("%d + %d + %d = %d\n",a,b,c,sum);
    printf("%d * %d * %d = %d\n",a,b,c,mult);
    return 0;
}
