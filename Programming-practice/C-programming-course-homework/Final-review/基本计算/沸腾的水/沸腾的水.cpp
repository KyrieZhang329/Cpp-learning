#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int m,s;
    cin>>m>>s;
    double t=m*1.0+s/60.0;
    double c;
    if(t<=10)
        c=100.0-5*t;
    else if(t<=30)
        c=50.0-(t-10);
    else if(t<=50)
        c=30.0-(t-30)/2;
    else    
        c=20.0;
    printf("%.1f",c);
    return 0;
}