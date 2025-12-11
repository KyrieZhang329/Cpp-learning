#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int factor[100];
	int cnt=0;
	int index=n;
	for(int i=2;i*i<=n;i++)
	{
		while(index%i==0)
		{
			factor[cnt++]=i;
			index/=i;
		}
	}
	if(index>1)
	{
		factor[cnt++]=index;
	}
	for(int m=0;m<cnt;m++)
	{
		if(m>0)
		{
			printf("*");
		}
		printf("%d",factor[m]);
	}
	return 0;
}
