#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    double c=a*1.0+sqrt(b*a+1);
    double t=a*pow(c+b,2);
    double s=t*c+pow(b,2);
    printf("CL=%d tD=%d SP=%d",static_cast<int>(c),static_cast<int>(t),static_cast<int>(s));
    return 0;
}