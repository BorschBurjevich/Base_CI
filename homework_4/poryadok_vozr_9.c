#include <stdio.h>
int main (void)
{
	int a,b,c;
	printf("Enter three integers: \n");
    scanf("%d%d%d",&a,&b,&c);
	if ((a < b)&&(a < c))
	{
		if (b < c)
		{
			printf("YES\n");
		}
		else 
		{
			printf("NO\n");
		}
	}
	else
	{
		printf ("NO\n");
	}
	return 0;
}	