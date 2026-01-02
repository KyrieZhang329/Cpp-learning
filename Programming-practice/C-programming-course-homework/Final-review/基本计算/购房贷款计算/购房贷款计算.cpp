#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    double d,p,r;
    cin>>d>>p>>r;
    double m=log(p/(p-d*r))/log(1+r);
    printf("%.2f",m);
    return 0;
}