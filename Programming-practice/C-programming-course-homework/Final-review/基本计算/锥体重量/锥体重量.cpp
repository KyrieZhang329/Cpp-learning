#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int d,h;
    cin>>d>>h;
    double pi=3.1415926;
    double v=1.0/3.0*pi*pow(d/2.0,2)*h;
    double m1=static_cast<int>(7.86*v/1000),m2=static_cast<int>(19.3*v/1000);
    cout<<m1<<" "<<m2;
    return 0;
}