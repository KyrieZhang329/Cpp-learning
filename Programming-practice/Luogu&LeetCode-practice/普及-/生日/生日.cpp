#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct people{
    string s;
    int turn;
    int y;
    int m;
    int d;
};

bool cmp(people a,people b)
{
    if(a.y==b.y)
    {
        if(a.m==b.m)
        {
            if(a.d==b.d)
                return a.turn>b.turn;
            return a.d<b.d;
        }
        return a.m<b.m;
    }
    return a.y<b.y;
}

int main()
{
    int n;
    cin>>n;
    vector<people> v(n);
    for(int i=0;i<n;i++)
    {
        v[i].turn=i;
        cin>>v[i].s>>v[i].y>>v[i].m>>v[i].d;
    }
    sort(v.begin(),v.end(),cmp);
    for(people i:v)
        cout<<i.s<<endl;
    return 0;
        
}