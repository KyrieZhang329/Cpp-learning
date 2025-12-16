#include<iostream>
#include<string>
using namespace std;

string copystr(const string& str,const int& m)
{
    string result;
    result.assign(str.begin()+m-1,str.end());
    return result;
}

int main()
{
    string str;
    int m;
    getline(cin,str);
    cin>>m;
    if((int)str.size()<m)
        cout<<"error";
    else
    {
        string result=copystr(str,m);
        cout<<result;
    }
    return 0;
}