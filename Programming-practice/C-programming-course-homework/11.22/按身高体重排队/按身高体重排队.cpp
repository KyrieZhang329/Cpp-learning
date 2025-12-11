#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct stu
{
    int num;
    int h;
    int w;
};

bool cmp(stu a,stu b)
{
    if(a.h!=b.h)
        return a.h < b.h;
    return a.w<b.w;
}

int main()
{
    int n;
    cin>>n;
    vector<stu>v(n);
    for(int i=0;i<n;i++)
    {    
        v[i].num=i+1;
        cin>>v[i].h;
    }
    for(int j=0;j<n;j++)
        cin>>v[j].w;
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++)
        cout<<v[i].num<<" ";
    return 0;
}