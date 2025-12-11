#include<iostream>
#include<vector>
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
    int m;
    cin >> m;
    vector<vector<int> >arr(m, vector<int>(m));
    for (int i = 0; i < m; i++) 
	{
        for (int j = 0; j < m; j++) 
            cin >> arr[i][j];
    }
    int total = 2 * m + 2; 
    int* sums = new int[total](); 
    for (int i = 0; i < m; i++) 
	{
        for (int j = 0; j < m; j++) 
            sums[i] += arr[i][j];
    }
    for (int i = m; i < 2 * m; i++) 
	{
        int col = i - m; 
        for (int row = 0; row < m; row++) 
            sums[i] += arr[row][col];
    }
    int main_diag = 2 * m;
    for (int i = 0; i < m; i++) 
        sums[main_diag] += arr[i][i];
    int sub_diag = 2 * m + 1;
    for (int i = 0; i < m; i++) 
        sums[sub_diag] += arr[i][m - 1 - i];
	BubbleSort(sums, total);
    for (int i = 0; i < total; i++)
        cout << sums[i] << " ";
    cout << endl;
    delete[] sums;
    return 0;
}
	
