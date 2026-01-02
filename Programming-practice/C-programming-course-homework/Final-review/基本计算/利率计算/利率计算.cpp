#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    double r,n;
    cin>>r>>n;
    double p=pow(1+r,n);
    printf("%.2f",p);
    return 0;
}