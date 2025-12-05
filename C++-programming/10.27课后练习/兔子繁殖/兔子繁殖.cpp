#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int k=1;
	int m=k;
	int arr[50];
	for(int i=3;i<=n;i++)
	{
		if(i>=5)
			{
				k+=arr[i-5];
			}
		arr[i-3]=k;
		m+=k;
	}
	printf("%d",m);
	return 0;
}
/*
遍历每个月 从第3个月开始有小兔子
每对小兔子在出生后第个月开始生 

int k=n;  k表示有生育能力的兔子  m表示总共兔子 
arr数组用来存储还没有剩余能力的兔子 
int cnt=0
int arr[50] 
for(i=3;i<=n;i++)
{
n*=2;
arr[cnt++]=k
从第6个月开始，第一对小兔子开始生孩子 
k+=arr[cnt-2]

  
*/
