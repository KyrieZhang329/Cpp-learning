#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int k,cnt=0;
    cin>>k;
    char str[101];
    char c1,c2;
    cin>>str>>c1>>c2;
    int len=strlen(str);
    if(len<k)
    {
        cout<<0;
        return 0;
    }
    else
    {
        for(int i=0;i<=len-k;i++)
        {
            for(int j=k;j<=len-i;j++)
            {
                if(str[i]==c1&&str[i+j-1]==c2)
                    cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}