#include <stdio.h>

// Определить уравнение прямой по координатам двух точек.
// Уравнение вида y = k*x + b;
 
int main (void)
{
	int x_1,y_1,x_2,y_2;
	float k,b;
	printf("Enter two points with coordinates:\n");
	scanf("%d%d%d%d",&x_1,&y_1,&x_2,&y_2);
	// b = -k * x_1 + y_1 (1)
	// b = y_2 - k*x_2    (2)
	// приравниваем обе части уравнений
	//y_2 - k*x_2 = -k*x_1 + y_1
	//y_2 - y_1 = k(x_2 - x_1)
	//k = (y_2 - y_1)/(x_2 - x_1)
	// подставляем k в одно из уравнений 
	//b = ((-1)*(y_2 - y_1)/(x_2 - x_1)) * x_1 + y_1 
	k = (float)(y_2 - y_1)/(x_2 - x_1);
	b = (-1.0) * k * x_1 + y_1;
	printf("%.2f %.2f\n",k,b);	
	return 0;
}	