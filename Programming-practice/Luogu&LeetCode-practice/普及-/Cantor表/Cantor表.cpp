#include<iostream>
using namespace std;

int main() 
{
    int n; 
    cin >> n;
    int k = 1;
    while (k * (k + 1) / 2 < n) 
        k++;
    int pos = n - (k - 1) * k / 2;

    if (k % 2 == 0) 
        cout << pos << "/" << (k - pos + 1);
    else 
        cout << (k - pos + 1) << "/" << pos;
    return 0;
}