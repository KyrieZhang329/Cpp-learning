#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n*2];
	for(int i=0;i<n*2;i++)
		cin>>arr[i];
	for(int i=0;i<n;i++)
	{
		int temp=arr[i];
		arr[i]=arr[n+i];
		arr[n+i]=temp;
	}
	for(int i=0;i<n*2;i++)
		cout<<arr[i]<<" ";
	return 0;
} 
