#include<stdio.h>
int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	int result=0;
	int a=m;
	int b=n;
	int sum=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			sum=a*(b-j+1);
			result+=sum;
		}
		a--;
	 } 
	printf("%d",result);
	return 0;
}
