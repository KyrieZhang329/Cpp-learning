#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int cnt=0;
    char s=str[0];
    for(int i=0;i<str.size();i++)
    {
        if(str[i]>s)
        {   
            cnt=i;
            s=str[i];
        }
    }
    str.insert(cnt+1,1,'*');
    cout<<str;
}