#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int& i:v)
        cin>>i;
    int max=abs(v[1]-v[0]);
    for(int i=2;i<n;i++)
        max=abs(v[i]-v[i-1])>max?abs(v[i]-v[i-1]):max;
    cout<<max;
    return 0;
}