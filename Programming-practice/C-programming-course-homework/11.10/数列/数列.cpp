#include<iostream>
using namespace std;

int main()
{
	int a1, a2, n;
	cin >> a1 >> a2 >> n;
	int arr[n];
	arr[0] = a1;
	arr[1] = a2;
	int cnt=0; 
	for (int i = 2; i < n+1; i++)
	{
		int index = arr[i-2-cnt] * arr[i-1-cnt];
		if (index < 10)
			arr[i] = index;
		else
		{
			int x = index % 10;
			int y = index / 10;
			arr[i] = y;
			arr[i+1] = x;
			i += 1;
			cnt++;
		}
	}
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}
