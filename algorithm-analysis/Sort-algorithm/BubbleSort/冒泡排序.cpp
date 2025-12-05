#include<iostream>
using namespace std;

void BubbleSort(int* arr, int n)
{
    for(int i=0;i<n;i++) 
	{
        for(int j=1;j<n-i;j++) 
		{
            if (arr[j-1]>arr[j]) 
		    { 
                int temp=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

int main()
{
    int arr[14]={-5,9,11,13,32,4,1,10,88,2,8,3,16,14};
    int size=sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr,size);
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
}