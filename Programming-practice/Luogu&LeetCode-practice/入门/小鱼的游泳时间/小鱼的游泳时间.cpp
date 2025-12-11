#include<iostream>
using namespace std;

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int h,m;
    if(d>b)
    {
        h=c-a;
        m=d-b;
    }
    else
    {
        h=c-a-1;
        m=d+60-b;
    }
    cout<<h<<" "<<m;
    return 0;
}