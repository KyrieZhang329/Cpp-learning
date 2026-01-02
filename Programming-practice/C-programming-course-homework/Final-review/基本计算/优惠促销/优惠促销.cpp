#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    double discount=10.0;
    if(m)
    {
        cout<<"yes"<<" ";
        if(n>=500)
            discount=8.0;
        else if(n>=350)
            discount=8.5;
        else if(n>=200)
            discount=9.0;
    }
    else
    {
        cout<<"no"<<" ";
        if(n>=500)
            discount=9.0;
        else if(n>=350)
            discount=9.5;
    }
    double total=n*discount/10;
    double diff=n-total;
    printf("%.1f %.1f %.1f",n*1.0,total,diff);
    return 0;
}