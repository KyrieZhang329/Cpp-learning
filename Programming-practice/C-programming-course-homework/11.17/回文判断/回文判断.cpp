#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char str[101];
    cin>>str;
    int len=strlen(str);
    int n=len/2;
    bool index=1;
    for(int i=0;i<n;i++)
    {
        if(str[i]!=str[len-1-i])
            index=0;
    }
    if(index)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}