#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() 
{
    int n;
    cin >> n;
    vector<vector<int> > mat(n, vector<int>(n));
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
            cin >> mat[i][j];
    }
    
    vector<int> result;
    for (int k = 0; k <= 2 * n - 2; ++k)
    {
        int max_row = min(n - 1, k);       
        int min_row = max(0, k - (n - 1)); 
        if (k % 2 == 0) 
        {

            for (int i = max_row; i >= min_row; --i) 
            {
                int j = k - i; 
                result.push_back(mat[i][j]);
            }
        } 
        else 
        {
            for (int i = min_row; i <= max_row; ++i)
            {
                int j = k - i;
                result.push_back(mat[i][j]);
            }
        }
    }
    for (size_t i = 0; i < result.size(); ++i) 
    {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    return 0;
}