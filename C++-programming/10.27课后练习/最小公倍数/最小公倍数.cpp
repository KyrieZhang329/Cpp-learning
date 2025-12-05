#include<stdio.h>
int max(int a,int b)
{
	int maximum;
	if(a>b)
	{
		maximum=a;
	}
	else
	{
		maximum=b;
	}
	return maximum;
}

int main()
{
	int a,b;
	int result;
	scanf("%d %d",&a,&b);
	if(a%b==0&&a>b)
	{
		result=a;
	}
	else if(b%a==0&&a<b)
	{
		result=b;
	}
	else
	{
		for(int i=max(a,b)+1;;i++)
		{
			if(i%a==0&&i%b==0)
			{
				result=i;
				break;
			}
		}
	}
	printf("%d",result);
	return 0;
}
