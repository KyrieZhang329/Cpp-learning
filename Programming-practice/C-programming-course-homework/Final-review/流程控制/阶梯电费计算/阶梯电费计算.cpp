#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    double n;
    cin>>n;
    double sum=0.0;
    if(n<=110)
        sum=0.5*n;
    else if(n<=210)
        sum=0.5*110+(n-110)*0.55;
    else
        sum=0.5*110+100*0.55+(n-210)*0.7;
    printf("%.2f",sum);
    return 0;
}