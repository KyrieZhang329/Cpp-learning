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
	int sort[2][n];
	int cnt1=0,cnt2=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]%2==0)
			sort[0][cnt1++]=arr[i];
		else 
			sort[1][cnt2++]=arr[i];
	}
	int*a=&sort[0][0];
	int*b=&sort[1][0];
	BubbleSort(a,cnt1);
	BubbleSort(b,cnt2);
	for(int i=0;i<cnt1;i++)
		cout<<sort[0][i]<<" ";
	for(int i=0;i<cnt2;i++)
	{
		cout<<sort[1][i];
		if(i!=cnt2-1)
			cout<<" ";
	}
	return 0;
}
