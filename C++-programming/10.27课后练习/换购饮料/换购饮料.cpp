#include<stdio.h>
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int cnt=n; 
	do{
		int i=n/k;
		cnt+=i;
		n=n%k+i;
	}while(n>=k);
	printf("%d",cnt);
}
