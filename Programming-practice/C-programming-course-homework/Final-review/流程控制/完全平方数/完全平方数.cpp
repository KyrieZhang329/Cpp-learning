#include<iostream>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    for(long long i=0;i*i<=n;i++)
    {
        if(i*i==n)
        {
            cout<<i;
            return 0;
        }
    }
    cout<<"no";
    return 0;
}