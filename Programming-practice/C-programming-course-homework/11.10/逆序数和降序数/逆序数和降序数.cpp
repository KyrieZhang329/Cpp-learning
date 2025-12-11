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
	int arr[7];
	for(int i=0;i<7;i++)
	{
		arr[i]=n%10;
		n/=10;
	}
	int cnt=0;
	for(int i=6;i>=0;i--)
	{
		if(arr[i]!=0)
		{
			cnt=i;
			break;
		}
	}
	int a=0,b=0;
	for(int i=0;i<=cnt;i++)
	{
		a+=arr[i];
		if(i!=cnt)
			a*=10;
	}
	BubbleSort(arr,cnt+1);
	for(int i=0;i<=cnt;i++)
	{
		b+=arr[i];
		if(i!=cnt)
			b*=10;
	}
	cout<<a+b;
	return 0;
}
