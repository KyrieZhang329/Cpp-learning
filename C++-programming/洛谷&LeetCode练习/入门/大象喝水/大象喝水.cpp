#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int h,r;
    cin>>h>>r;
    double v=3.14*pow((double)r,2)*(double)h;
    int V=20*1000;
    int n=(int)ceil((double)V/v);
    cout<<n;
}