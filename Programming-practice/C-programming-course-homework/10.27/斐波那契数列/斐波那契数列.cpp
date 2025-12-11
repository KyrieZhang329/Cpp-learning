#include<stdio.h>
int main()
{
	int m;
	scanf("%d",&m);
	int arr[50];
	arr[0]=7;
	arr[1]=11;
	for(int i=2;i<=m;i++)
	{
		arr[i]=arr[i-1]+arr[i-2];
	}
	printf("%d %d",m,arr[m]);
	return 0;
}
