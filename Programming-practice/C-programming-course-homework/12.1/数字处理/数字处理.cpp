#include<iostream>
using namespace std;

int Dispose(int n);

int main()
{
    int n;
    cin>>n;
    cout<<Dispose(n);
    return 0;
}

int Dispose(int n)
{
    int sum=0;
    while(n>0)
    {
        sum+=n%10;
        n/=10;
    }
    while(sum>=10)
        sum=Dispose(sum);
    return sum;
}