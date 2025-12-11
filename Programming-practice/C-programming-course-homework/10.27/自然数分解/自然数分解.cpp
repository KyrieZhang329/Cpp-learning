#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int a;
	for (a = 1;; a += 2)
	{

		int b;
		int sum=0;
		int i;
		for (i = 1; i <= n; i++)
		{
			sum += a + (i-1)* 2;
		}
		if (n * n * n == sum)
		{
			break;
		}
	}
	for (int index = n; index > 0; index--)
	{
	
		printf("%d", a);
	    a += 2;
		if (index != 1)
		{
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}
