#include<iostream>
using namespace std;

void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n - i; j++)
		{
			if (a[j - 1] > a[j])
			{
				int temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
	}
}

int main()
{
		int n;
		cin >> n;
		int a[10];
		for (int i = 0; i < 10; i++)
		{
			a[i] = n % 10;
			n /= 10;
		}
		int cnt = 0, index = 1, sum = 0;
		for (int i = 9; i >= 0; i--)
		{
			if (a[i] != 0)
			{
				cnt = i;
				break;
			}
		}
		BubbleSort(a, cnt+1);
		for (int i = 0; i <= cnt; i++)
			cout << a[i] << " ";
}
