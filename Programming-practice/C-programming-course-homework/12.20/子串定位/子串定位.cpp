#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string str,tar;
    cin>>str>>tar;
    int it=static_cast<int>(str.find(tar,0));
    if(it!=static_cast<int>(string::npos))
        cout<<it;
    else
        cout<<"-1";
    return 0;
}