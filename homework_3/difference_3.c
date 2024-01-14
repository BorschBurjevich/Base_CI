#include <stdio.h>
// Ввести два числа и найти их разность
int main (void)
{
    int a,b;
    printf("Enter two integers: \n");
    scanf("%d%d",&a,&b);
    a = a - b;
    printf("%d",a);
    return 0;
}
