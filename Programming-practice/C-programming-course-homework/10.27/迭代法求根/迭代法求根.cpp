#include<stdio.h>
#include<math.h>
int main()
{
	float a;
	scanf("%f",&a);
	float x=a;
	float x0;
	do{
	x0=x;
	x=0.5*(x0+a/x0);
}while(fabs(x - x0) >= 0.00001);
	printf("%.5f",x);
	return 0;
}
