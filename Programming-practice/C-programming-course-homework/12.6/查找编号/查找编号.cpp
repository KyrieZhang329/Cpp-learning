#include<iostream>
#include<vector>
using namespace std;

bool isPrime(int n);

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=1;i<=n;i++)
    {
        if(isPrime(i))
            v.push_back(i);
    }
    bool found=false;
    for(int i=1;i<(int)v.size();i++)
    {
        if(v[i]-v[i-1]==2)
        {
            cout<<v[i-1]<<" "<<v[i]<<endl;
            found=true;
        }
    }
    if(!found)
        cout<<"empty";
    return 0;
}

bool isPrime(int n)
{
    if(n==2)
        return true;
    else if(n==1||n%2==0)
        return false;
    else
    {
        for(int i=3;i*i<=n;i+=2)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }
}