#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    double pi=3.1415926;
    double ma=4.0/3.0*pi*pow(a/20.0,3)*7.86;
    double mb=4.0/3.0*pi*pow(b/20.0,3)*19.3;
    printf("%.3f %.3f",ma,mb);
    return 0;
}