#include <stdio.h>

int main (void)
{
	int a,b;
	printf("Enter two integers:\n");
	scanf("%d%d",&a,&b);
	if (a > b)
	{
		printf("Above\n");
	}
	else if (a < b)
	{
		printf("Less\n");
    }
	else 
    {
        printf("Equal\n");
	}
    return 0;	
}	