#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int l,m;
    cin>>l>>m;
    vector<pair<int,int> > v(m);
    for(int i=0;i<m;i++)
        cin>>v[i].first>>v[i].second;
    sort(v.begin(),v.end());
    for(int i=0;i<(int)v.size()-1;)
    {
        if(v[i].second>=v[i+1].first)
        {
            v[i].second=max(v[i].second,v[i+1].second);
            auto it=v.begin()+i+1;
            it=v.erase(it);
        }
        else
            i++;
    }
    int sum=l+1;
    for(int i=0;i<(int)v.size();i++)
        sum-=v[i].second+1-v[i].first;
    cout<<sum;
    return 0;
}