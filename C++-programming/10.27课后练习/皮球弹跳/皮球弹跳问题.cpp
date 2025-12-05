#include<stdio.h>
#include<math.h>
int main()
{
	long h,n;
	scanf("%ld %ld",&h,&n);
	double height=(double)h;
	double distance=height;
	for(long i=1;i<=n;i++)
	{
		height/=2.0;
		distance+=2.0*height;
		if(i==n)
		{
			distance-=2.0*height;
		}
	}
	distance=round(distance*10)/10.0;
	height=round(height*10)/10.0;
	printf("%.1lf %.1lf",distance,height);
	return 0;
}
