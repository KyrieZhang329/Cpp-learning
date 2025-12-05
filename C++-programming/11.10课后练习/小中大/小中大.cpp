#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	int max=0,min=0,mid=0;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	if(arr[1]>arr[0])
	{
		max=arr[n-1];
		min=arr[0];
	}
	else
	{
		max=arr[0];
		min=arr[n-1];
	}
	if(n%2==0)
		mid=(arr[n/2-1]+arr[n/2])/2;
	else
		mid=arr[n/2];
	cout<<max<<" "<<mid<<" "<<min;
	return 0;
}
