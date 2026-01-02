#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string str;
    cin>>str;
    for(int i=0;i<static_cast<int>(str.size());i+=2)
    {
        str[i]=tolower(str[i]);
        cout<<str[i];
    }
    cout<<'!';
    return 0;
}