#include<iostream>
#include<string>
using namespace std;

int chaNum(string s);

int main()
{
    string str;
    cin>>str;
    cout<<chaNum(str);
    return 0;
}

int chaNum(string s)
{
    int num=0;
    for(int i:s)
    {
        if((i>='a'&&i<='z')||(i>='A'&&i<='Z'))
            num++;
    }
    return num;
}