#include<iostream>
#include<cmath>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

struct pos{
    int x;
    int y;
    int z;
};

double dis(pos& a,pos& b)
{
    double distance=sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2)+pow(a.z-b.z,2));
    return distance;
}

bool cmp(pos& a,pos& b)
{
    return a.z<b.z;
}

int main()
{
    int n;
    cin>>n;
    vector<pos> v(n);
    for(pos& i:v)
        cin>>i.x>>i.y>>i.z;
    sort(v.begin(),v.end(),cmp);
    double sum=0.0;
    for(int i=1;i<n;i++)
        sum+=dis(v[i-1],v[i]);
    printf("%.3lf",sum);
    return 0;
}