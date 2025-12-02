#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

bool cmp(const pair<string,int>& a, const pair<string,int>& b);

int main()
{
    int n;
    cin>>n;
    vector<pair<string,int> > v(n);
    for(int i=0;i<n;i++)
    {
        v[i].second=i+1;
        cin>>v[i].first;
    }
    sort(v.begin(),v.end(),cmp);
    cout<<v[0].second<<endl<<v[0].first;
    return 0;
}


    bool cmp(const pair<string,int>& a, const pair<string,int>& b) 
{
    if (a.first.size()!=b.first.size()) 
        return a.first.size()>b.first.size();
    return a.first>b.first;
}