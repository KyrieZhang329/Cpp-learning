#include<iostream>
using namespace std;

int fib(int n);

int main()
{
    int n;
    cin>>n;
    cout<<fib(n);
    return 0;
}

int fib(int n)
{
    if(n==0)
        return 7;
    if(n==1)
        return 11;
    else
        return fib(n-1)+fib(n-2);
}