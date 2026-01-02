#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str;
    cin>>str;
    for(const char& i:str)
        cout<<i<<" ";
    return 0;
}