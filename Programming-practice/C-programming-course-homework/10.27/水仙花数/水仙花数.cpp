#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	if(n<100||n>999)
	{
		printf("-1");
	}
	else
	{
		int arr[3];
		int index=n;
		for(int i=0;i<=2;i++)
		{
			arr[i]=index%10;
			index/=10;
		}
		int judge=arr[0]*arr[0]*arr[0]+arr[1]*arr[1]*arr[1]+arr[2]*arr[2]*arr[2];
		if(judge==n)
		{
			printf("YES");
		}
		else
		{
			printf("NO");
		}
	}
	return 0;
 } 
