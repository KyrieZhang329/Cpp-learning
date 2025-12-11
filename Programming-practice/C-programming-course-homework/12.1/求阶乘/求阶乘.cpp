#include<iostream>
using namespace std;

unsigned long long fact(int n);

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cout<<fact(i)<<" ";
    return 0;    
}

unsigned long long fact(int n)
{
    if(n==1)
        return 1;
    else
        return n*fact(n-1);
}
