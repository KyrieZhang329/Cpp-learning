#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    int h,m;
    cin>>h>>m;
    double t=h*1.0+m/60.0;
    double T=4*pow(t,2)/(t+2)-20;
    printf("%.2f",T);
    return 0;
}