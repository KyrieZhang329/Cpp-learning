#include<stdio.h>
int main()
{
	int result=0;
	int m;
	int index=0;
	for(int i=0;;i++)
	{
		int n;
		scanf("%d",&n);
		if(n==0)
		{
			break;
		}
		else if(n==1)
		{
			result+=1;
			index=0;
			m=0;
		}
		else if(n==2)
		{
			if(index==1)
			{
				m+=2;
				result+=m;
			}
			else if(index==0)
			{
				index=1;
				m=2;
				result+=m;
			}
			
		}
	}
	printf("%d\n",result);
	return 0;
}
