#include<iostream>
using namespace std;

int main()
{
	int n,k,index=0;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<n;i++)
	{
		if(k==arr[i])
		{
			index=1;
			cout<<i<<" ";
		}
	}
	if(index==0)
		cout<<"-1";
	return 0;
}
