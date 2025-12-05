#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

bool cmp(pair<int,int>& v1,pair<int,int>& v2)
{
    if(v1.second==v2.second)
        return v1.first<v2.first;
    return v1.second>v2.second;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int> > v(n);
    for(pair<int,int>& i:v)
        cin>>i.first>>i.second;
    sort(v.begin(),v.end(),cmp);
    int num=(int)floor(m*1.5);
    int line=v[num-1].second;
    for(int i=num;i<(int)v.size();i++)
    {
        if(v[i].second==v[num-1].second)
        {
            num++;
            line=v[i].second;
        }
        else
            break;
    }
    cout<<line<<" "<<num<<endl;
    for(int i=0;i<num;i++)
        cout<<v[i].first<<" "<<v[i].second<<endl;
    return 0;
}