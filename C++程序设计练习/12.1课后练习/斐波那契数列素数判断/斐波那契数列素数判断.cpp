#include<iostream>
using namespace std;

int fibonacci(int n);
bool isPrime(int n);

int main()
{
    int n;
    cin>>n;
    if(isPrime(fibonacci(n)))
        cout<<"yes";
    else
        cout<<fibonacci(n);
    return 0;
}

int fibonacci(int n)
{
    if (n <= 2)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

bool isPrime(int n)
{
    if(n==2)
        return true;
    else if(n==1||n%2==0)
        return false;
    for(int i=3;i*i<=n;i+=2)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
