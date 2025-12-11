#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int> > cnt(k + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; ++i) 
    { 
        for (int j = 0; j < m; ++j) 
        { 
            int day;
            cin >> day;
            cnt[day][j + 1] = 1;
        }
    }

    for (int day = 1; day <= k; ++day) 
    {
        int res = 0;
        for (int p = 1; p <= m; ++p) 
            res += cnt[day][p];
        cout << res << " ";
    }
    return 0;
}