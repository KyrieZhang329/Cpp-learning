#include<iostream>
using namespace std;

void printFactorial(int n);

int main()
{
    int n;
    cin>>n;
    printFactorial(n);
    return 0;
}

void printFactorial(int n)
{
    long long result=1;
    if(n>1000||n<0)
    {
        cout<<"Invalid input";
        return;
    }
    else
    {
        if(n==1||n==0)
        {
            cout<<result;
            return;
        }
        else
        {
            for(int i=n;i>=1;i--)
                result*=i;
        }
        cout<<result;
    }
}