#include<stdio.h>
int main()
{
	int m;
	char c;
	scanf("%d %c",&m,&c);
	int cnt=m;
	for(int i=1;i<=m;i++)
	{
		for(int k=1;k<=cnt-1;k++)
		{
			printf(" ");
		}
		for(int j=1;j<=i;j++)
		{
			printf("%c",c);
			if(j<i)
			{
				printf(" ");
			}
			else if(j==i&&i!=m)
			{
				printf("\n");
			}
		}
		cnt--;
	}
	return 0;
}

