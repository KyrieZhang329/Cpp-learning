#include<iostream>
using namespace std;

bool is_prime(const int& n)
{
    if(n==2)
        return true;
    else if(n%2==0||n==1)
        return false;
    else
    {
        for(int i=3;i*i<=n;i+=2)
        {
            if(n%i==0)
                return false;
        }
    }
    return true; 
}

int main()
{
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        if(is_prime(i)&&is_prime(n-i))
        {
            cout<<i<<" "<<n-i;
            break;
        }
        if(i%2!=0)
            i++;
    }
    return 0;
}