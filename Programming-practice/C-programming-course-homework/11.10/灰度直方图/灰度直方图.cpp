#include<iostream>
using namespace std;

int main()
{
	int m,n;
	cin>>m>>n;
	int arr[m*n];
	for(int i=0;i<m*n;i++)
		cin>>arr[i];
	int value[16];
	int count[16]={0};
	for(int i=0;i<m*n;i++)
	{
		for(int j=0;j<16;j++)
		{
			if(arr[i]==j)
				count[j]++;
		}
	}
	for(int i=0;i<16;i++)
	{
		if(count[i]!=0)
			cout<<i<<" "<<count[i]<<"\n";
	}
	return 0;
}
