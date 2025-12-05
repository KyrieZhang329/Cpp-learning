#include<stdio.h>
int main()
{
	int mode,n;
	scanf("%d %d",&mode,&n);
	if(mode==0)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				printf("%d*%d=%d",i,j,i*j);
				if(i!=j)
				{
					printf("  ");
				}
				else if(i==j&&i!=n)
				{
					printf("\n");
				}
			}
		}
	}
	else if(mode==1)
	{
		for(int k=1;k<=n;k++)
			{
				printf("%d*%d=%d",n,k,n*k);
				if(n!=k)
				{
					printf("  ");
				}
			}	
	}
	return 0;
 } 
