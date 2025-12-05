#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str;
    cin>>str;
    for(int i=0;i<str.size();i++)
    {
        if((str[i]>='w'&&str[i]<='z')||(str[i]>='W'&&str[i]<='Z'))
            str[i]-=26;
        str[i]+=4;
    }
    cout<<str;
}