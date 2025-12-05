#include<iostream>
using namespace std;

int main()
{
	int arr1[6],arr2[6];
	for(int i=0;i<6;i++)
		cin>>arr1[i];
	for(int i=0;i<6;i++)
		cin>>arr2[i];
	int sum[4];
	sum[0]=arr1[0]*arr2[0]+arr1[1]*arr2[2]+arr1[2]*arr2[4];
	sum[1]=arr1[0]*arr2[1]+arr1[1]*arr2[3]+arr1[2]*arr2[5];
	sum[2]=arr1[3]*arr2[0]+arr1[4]*arr2[2]+arr1[5]*arr2[4];
	sum[3]=arr1[3]*arr2[1]+arr1[4]*arr2[3]+arr1[5]*arr2[5];
	cout<<sum[0]<<" "<<sum[1]<<endl;
	cout<<sum[2]<<" "<<sum[3]<<endl;
	return 0;
} 
