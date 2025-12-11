#include<stdio.h>
#include<math.h>
int main()
{
	long n;
	long arr[100];
	int cnt=0;
	scanf("%ld",&n);
	if(n%2!=0)
	{
		int end=-1;
		printf("%d",end);
	}
	else 
	{
	for(int i=29;i>0;i--)
	{
      long power=1L<<i;
      if(power<=n)
      {
      	arr[cnt++]=power;
      	n-=power;
	  }
	}
	}
	for(int j=0;j<cnt;j++)
	{
		if(j>0)
		{
			printf(" ");
		}
		printf("%ld",arr[j]);
	}
	return 0;
}
