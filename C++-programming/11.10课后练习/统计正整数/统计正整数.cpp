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
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	BubbleSort(arr,n);
	int sort[n];
	int count[n]={0};
	int m=0;
	int current=arr[0];
	int cnt=1;
	for (int i = 1; i < n; i++) 
	{
        if (arr[i] == current) 
            cnt++;  
		else 
		{
            sort[m] = current;
            count[m++] = cnt;
            current = arr[i];
            cnt = 1;
        }
    }
    sort[m] = current;
    count[m++] = cnt;
	for(int i=0;i<m;i++)
		cout<<sort[i]<<":"<<count[i]<<endl;
	return 0;
}
