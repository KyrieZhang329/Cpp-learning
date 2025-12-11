#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int m, n;
    cin >> m >> n; 
    vector<vector<int> > arr(m, vector<int>(n, 0));
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int r = 0, c = 0; 
    int dir = 0;
    for (int num = 1; num <= m * n; ++num) 
	{
        arr[r][c] = num;  
        int next_r = r + dirs[dir][0];
        int next_c = c + dirs[dir][1];
        if (next_r >= 0 && next_r < m && next_c >= 0 && next_c < n && arr[next_r][next_c] == 0) 
		{
            r = next_r;
            c = next_c;
        } 
		else 
		{
            dir = (dir + 1) % 4;
            r += dirs[dir][0];
            c += dirs[dir][1];
        }
    }
    for (int i = 0; i < m; ++i) 
	{
        for (int j = 0; j < n; ++j) 
		{
            if (j == 0)
			{
                cout << arr[i][j]; 
            } 
			else 
			{
                cout << " " << arr[i][j]; 
            }
        }
        cout << endl; 
    }
    return 0;
}
