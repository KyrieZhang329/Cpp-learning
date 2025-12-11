#include <iostream>
#include <cstring>
using namespace std;

int memo[201][7];
int count(int n, int k) 
{
    if (k == 1) 
        return 1;
    if (n < k) 
        return 0;
    if (memo[n][k] != -1) 
        return memo[n][k];
    memo[n][k] = count(n-1, k-1) + count(n-k, k);
    return memo[n][k];
}

int main() 
{
    int n, k;
    cin >> n >> k;
    memset(memo, -1, sizeof(memo));
    cout << count(n, k) << endl;
    return 0;
}