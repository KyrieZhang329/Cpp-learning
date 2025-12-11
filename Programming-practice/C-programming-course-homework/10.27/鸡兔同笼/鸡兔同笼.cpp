#include<stdio.h>
int main()
{
	int m,n,a,b;
	scanf("%d %d",&m,&n);
	b=(1.0/2.0)*(n-2*m);
	a=m-b;
	int a1=int(a);
	int b1=int(b);
	printf("%d %d",a1,b1);
	return 0;
}
/*
a+b=m  2a+4b=n
*/
