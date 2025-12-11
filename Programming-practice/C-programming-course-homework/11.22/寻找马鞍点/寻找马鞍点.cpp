#include<iostream>
#include<algorithm>
using namespace std;

int main(void) 
{
    int m, n;
    cin >> m >> n;
    int arr[m][n];
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
            cin >> arr[i][j];
    }
    bool found = false; 
    for (int i = 0; i < m; i++) 
    {
        int row_min_val = arr[i][0];
        int row_min_col = 0;
        for (int j = 1; j < n; j++) 
        {
            if (arr[i][j] < row_min_val) 
            {
                row_min_val = arr[i][j];
                row_min_col = j;
            }
        }
        bool is_col_max = true;
        for (int k = 0; k < m; k++) 
        {
            if (arr[k][row_min_col] > row_min_val) 
            {
                is_col_max = false;
                break;
            }
        }
        
        if (is_col_max) 
        {
            cout << i << " " << row_min_col << " " << row_min_val << endl;
            found = true;
            break; 
        }
    }
    if (!found)
        cout << "no" << endl;
    return 0;
}