#include<iostream>
using namespace std;

void BubbleSort(int* a, int n) 
{
    for (int i = 0; i < n; i++) 
	{
        for (int j = 1; j < n - i; j++) 
		{
            if (a[j-1] < a[j]) 
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
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	BubbleSort(arr,n);
	if(n%2==0)
		cout<<(arr[n/2-1]+arr[n/2])/2;
	else
		cout<<arr[n/2];
	return 0;
}
