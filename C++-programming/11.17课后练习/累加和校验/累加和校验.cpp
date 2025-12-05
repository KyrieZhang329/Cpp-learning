#include<iostream>
#include<cstring>
#include<numeric>
using namespace std;

int main()
{
    char str[101];
    int sum=0;
    cin.getline(str,101);
    int len=strlen(str);
    for(int i=0;i<len;i++)
        sum+=str[i];
    cout<<sum%256;
    return 0;
}
