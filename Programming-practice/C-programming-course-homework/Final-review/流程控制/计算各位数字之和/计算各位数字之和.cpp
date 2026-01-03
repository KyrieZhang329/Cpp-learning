#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int sum=0;
    for(const char& i:str) 
        sum+=i-'0';
    cout<<sum<<endl;
    return 0;
}