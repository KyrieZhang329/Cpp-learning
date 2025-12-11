#include<iostream>
#include<vector>
#include<cctype>
#include<cmath>
using namespace std;

int trans(string& s);

int main()
{
    string str;
    cin>>str;
    int result=trans(str);
    cout<<result;
    return 0;
}

int trans(string& s)
{
    int size=s.size();
    int result=0;
    for(int i=0;i<size;i++)
    {
        int x=toupper(s[i]);
        int value=0;
        if(x>='0'&&x<='9')
            value=x-'0';
        else if(x>='A'&&x<='F')
            value=x-'A'+10;
        result+=value*(int)pow(16,size-i-1);
    }
    return result;
}