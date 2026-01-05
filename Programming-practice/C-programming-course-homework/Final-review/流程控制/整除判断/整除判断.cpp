#include<iostream>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    if(a%b==0)
        cout<<"yes";
    else
        cout<<a/b<<" "<<a%b;
    return 0;
}