#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n<60)
        cout<<'E';
    else if(n<=69)
        cout<<'D';
    else if(n<=79)
        cout<<'C';
    else if(n<=89)
        cout<<'B';
    else
        cout<<'A';
    return 0;
}