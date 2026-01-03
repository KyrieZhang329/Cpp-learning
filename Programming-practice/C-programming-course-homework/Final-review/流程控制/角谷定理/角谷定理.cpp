#include<iostream>
using namespace std;

int main()
{
    int cnt=0,n;
    cin>>n;
    while(n!=1)
    {
        if(n%2==0)
            n/=2;
        else
            n=n*3+1;
        cnt++;
    }
    cout<<cnt;
    return 0;
}