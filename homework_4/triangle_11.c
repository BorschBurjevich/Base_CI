#include <stdio.h>
int main (void)
{
    unsigned int a,b,c;
    printf("Enter three length: \n");
    scanf("%d%d%d",&a,&b,&c);
    if ((a+b)>c)
    {
        printf("YES\n");
    }
    else if ((a+c)>b)
    {
        printf("YES\n");
    }
    else if ((b+c)>a)
    {
        printf("YES\n");
    }
    else
    {
      printf("NO\n");
    }
    return 0;
}
