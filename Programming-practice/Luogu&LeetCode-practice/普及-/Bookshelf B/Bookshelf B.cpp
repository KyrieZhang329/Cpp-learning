#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(const int& a,const int& b)
{
    return a>b;
}

int main()
{
    int b,n;
    cin>>n>>b;
    vector<int> v(n);
    for(int& i:v)
        cin>>i;
    sort(v.begin(),v.end(),cmp);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=v[i];
        if(sum>=b)
        {
            cout<<i+1;
            break;
        }
    }
    return 0;
}