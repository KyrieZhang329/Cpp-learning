#include <iostream>
#include <vector>
#include <cstdio> 
using namespace std;

int main() 
{
    int N;
    cin >> N; 
    vector<vector<int> > spiral(N, vector<int>(N, 0));
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int row = 0, col = 0;  
    int dir = 0;          
    for (int num = 1; num <= N * N; ++num) 
	{
        spiral[row][col] = num;  
        int next_row = row + dirs[dir][0];
        int next_col = col + dirs[dir][1];
        if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < N && spiral[next_row][next_col] == 0) 
		{
            row = next_row;
            col = next_col;
        } 
		else 
		{
            dir = (dir + 1) % 4;
            row += dirs[dir][0];
            col += dirs[dir][1];
        }
    }

    for (int i = 0; i < N; ++i) 
	{
        for (int j = 0; j < N; ++j) 
            printf("%-4d", spiral[i][j]);  
        cout << endl; 
    }
    return 0;
}
