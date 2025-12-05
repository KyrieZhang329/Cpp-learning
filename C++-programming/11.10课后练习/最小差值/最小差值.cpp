#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int diff[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
				diff[i][j]=abs(arr[i]-arr[j]);
		}
	}
	int min=diff[0][1];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i!=j)
			{
				if(diff[i][j]<min)
					min=diff[i][j];
			}
		}		
	}
	cout<<min<<endl;
	return 0;
}
