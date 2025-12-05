#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	scanf("%d",&n);
	double pi,pi4;
	pi4=0.0;
	for(int i=1;i<=n;i++)
	{
		pi4+=pow(-1,i-1)*(1.0/(2.0*i-1.0));
	}
	pi=4.0*pi4;
	printf("%.6lf",pi);
	return 0;
}
