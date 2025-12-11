#include<iostream>
using namespace std;

long long fun(int n);

int main()
{
    int n;
    cin>>n;
    long long result=fun(n);
    cout<<result;
    return 0;
}

long long fun(int n)
{
    if(n==1||n==2)
        return 1;
    if(n==3)
        return 2;
    return fun(n-1)+fun(n-3);
}