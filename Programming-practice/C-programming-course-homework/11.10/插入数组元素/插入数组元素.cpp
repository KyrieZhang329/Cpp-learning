#include<iostream>
using namespace std;

void BubbleSort(int* a, int n) 
{
    for (int i = 0; i < n; i++) 
	{
        for (int j = 1; j < n - i; j++) 
		{
            if (a[j-1] > a[j]) 
			{ 
                int temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main()
{
	int n;
	cin>>n;
	int arr[n+1];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int m;
	cin>>m;
	arr[n]=m;
	BubbleSort(arr,n+1);
	for(int i=0;i<n+1;i++)
		cout<<arr[i]<<" ";

	return 0;
}
