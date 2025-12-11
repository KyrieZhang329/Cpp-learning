#include<iostream>
using namespace std;

int main(void)
{
    int n,k;
    cin>>n>>k;
    int total=n;
    int a=0;
    while(a+n>=k)
    {
        int sum=a+n;
        a=sum/k;
        n=sum%k;
        total+=a;
    }
    cout<<total<<endl;
    return 0;
}