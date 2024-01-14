#include <stdio.h>

int main (void)
{
    int a,b,c,sum;
    printf("Enter three integers: \n");
    scanf("%d%d%d",&a,&b,&c);
    sum = a + b + c;
    printf("%d + %d + %d = %d\n",a,b,c,sum);
    return 0;
}
