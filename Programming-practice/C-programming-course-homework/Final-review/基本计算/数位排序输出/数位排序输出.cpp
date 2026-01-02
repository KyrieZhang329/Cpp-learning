#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string str=to_string(static_cast<int>(abs(n)));
    string re_str=str;
    reverse(re_str.begin(),re_str.end());
    for(const char& i:str)
        cout<<i<<" ";
    cout<<endl;
    for(const char& i:re_str)
        cout<<i<<" ";
    return 0;
}