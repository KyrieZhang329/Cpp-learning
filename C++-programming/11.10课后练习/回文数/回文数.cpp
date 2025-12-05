#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[10];
	for(int i=0;i<10;i++)
	{
		a[i]=n%10;
		n/=10;
	}
	int cnt=0,index=1,sum=0;
	for(int i=9;i>=0;i--)
	{
		if(a[i]!=0)
		{
			cnt=i;
			break;
		}
	}
	for(int i=0;i<=cnt/2;i++)
	{
		if(a[i]!=a[cnt-i])
		{
			index=0;
			break;
		}
	}
	if(index==0)
		cout<<"no";
	else
	{
		for(int i=0;i<=cnt;i++)
			sum+=a[i];
		cout<<sum;
	}
	return 0;
}
