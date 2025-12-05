#include<iostream>
using namespace std;

int main()
{
    int k,n;
    cin>>k;
    double sum=0.0;
    for(int i=1;;i++)
    {
        sum+=1.0/(i*1.0);
        if(sum>k)
        {
            n=i;
            break;
        }
    }
    cout<<n;
    return 0;
}