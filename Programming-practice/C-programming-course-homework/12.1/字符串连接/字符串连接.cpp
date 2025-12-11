#include<iostream>
#include<string>
using namespace std;

//因题目要求 本题不使用strcat函数和string相加减
string strLink(string s,string t);

int main()
{
    string s,t;
    cin>>s>>t;
    cout<<strLink(s,t);
    return 0;
}

string strLink(string s,string t)
{
    for(int i:t)
        s.push_back(i);
    return s;
}