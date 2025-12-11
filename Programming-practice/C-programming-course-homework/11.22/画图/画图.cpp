#include<iostream>
#include<vector>
#include<utility>
using namespace std;

typedef struct
{
    pair<int,int> s;
    pair<int,int> t;
} rectangle;

int main()
{
    int n;
    cin>>n;
    vector<rectangle> v(n);
    for(int i=0;i<n;i++)
    {
        int x,y,z,k;
        cin>>x>>y>>z>>k;
        v[i].s=make_pair(x,y);
        v[i].t=make_pair(z,k);
    }
    vector<vector<int> >arr(101,vector<int>(101,0));
    for(int i=0;i<v.size();i++)
    {
        for(int j=v[i].s.first;j<v[i].t.first;j++)
        {
            for(int k=v[i].s.second;k<v[i].t.second;k++)
                arr[j][k]=1;
        }
    }
    int sum=0;
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[i].size();j++)
            sum+=arr[i][j];
    }
    cout<<sum;
    return 0;
}