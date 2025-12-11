#include<stdio.h>
int main()
{
	int m;
	scanf("%d",&m);
	int arr[1000];
	int cnt=0;
	for(int i=10000;i<=99999;i++)
	{
		int index=i;
		int dis[5];
		for(int k=0;k<=4;k++)
		{
			dis[k]=index%10;
			index/=10;
		}
		if(dis[0]==dis[4]&&dis[1]==dis[3])
		{
			arr[cnt++]=i;
		}
	}
	int num=0;
	for(int j=0;j<cnt;j++)
	{
		if(arr[j]%m==0)
		{
			num++;
		}
	}
	printf("%d %d",m,num);
	return 0;
}
