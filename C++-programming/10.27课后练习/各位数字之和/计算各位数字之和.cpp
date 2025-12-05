#include<stdio.h>
int main()
{
	long n;
	scanf("%ld",&n);
	int cnt,i,sum;
	sum=0;
	for(i=0;i<=9;i++)
	{
		cnt=n%10;
		n/=10;
		sum+=cnt;
	}
	printf("%d",sum);
	return 0;
}
