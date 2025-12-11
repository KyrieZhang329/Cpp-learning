#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int m, n;
    cin >> m >> n;
    vector<vector<int> > mat(m, vector<int>(n));
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
            cin >> mat[i][j];
    }
    
    for (int i = 0; i < m; i++) 
    {
        int start = -1;       
        int max_start = -1;   
        int max_end = -1;    
        int max_len = 0;     
        
        for (int j = 0; j < n; j++) 
        {
            if (mat[i][j] == 1) 
            {
                if (start == -1) 
                    start = j;  
                int curr_len = j - start + 1; 
                if (curr_len > max_len) 
                {
                    max_len = curr_len;
                    max_start = start;
                    max_end = j;
                }
            } 
            else 
                start = -1; 
        }
        cout << max_start << " " << max_end << endl;
    }
    return 0;
}