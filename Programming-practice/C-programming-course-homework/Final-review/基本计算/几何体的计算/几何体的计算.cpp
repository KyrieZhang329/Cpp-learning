#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int r1,h1,r2,h2;
    cin>>r1>>h1>>r2>>h2;
    double pi=3.1415926;
    double v1=pi*pow(r1/2.0,2)*h1;
    double v2=1.0/3.0*pi*pow(r2/2.0,2)*h2;
    double v=v1-v2;
    double m=v*0.785;
    cout<<static_cast<int>(v)<<" "<<static_cast<int>(m);
    return 0;
}