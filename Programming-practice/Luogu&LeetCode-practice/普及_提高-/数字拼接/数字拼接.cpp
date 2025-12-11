#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(string& a,string& b)
{
    return a+b>b+a;
}

int main()
{
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<n;i++)
        cout<<v[i];
    return 0;
}