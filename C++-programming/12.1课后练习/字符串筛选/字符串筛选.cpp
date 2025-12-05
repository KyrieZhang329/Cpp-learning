#include<iostream>
using namespace std;

string Dispose(string s);

int main()
{
    string str;
    cin>>str;
    cout<<Dispose(str);
    return 0;
}

string Dispose(string s)
{
    for(int i=(int)s.size()-1;i>=0;i--)
    {
        if(i%2!=0)
            s.erase(i,1);
    }
    return s;
}
