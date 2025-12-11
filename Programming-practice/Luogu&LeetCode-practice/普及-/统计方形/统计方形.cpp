#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int min_val=min(n,m);
    int max_val=max(m,n);
    long long squ=0,rec=0;
    for(int i=0;i<=min_val;i++)
        squ+=(min_val-i)*(max_val-i);
    for(int i=0;i<=min_val;i++)
    {
        for(int j=0;j<=max_val;j++)
            rec+=(max_val-j)*(min_val-i);
    }
    rec-=squ;
    cout<<squ<<" "<<rec;
    return 0;
}