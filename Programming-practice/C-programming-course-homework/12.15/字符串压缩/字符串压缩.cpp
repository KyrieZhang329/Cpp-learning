#include<iostream>
#include<string>
using namespace std;

bool isNum(const char& a)
{
    return a>='0'&&a<='9';
}

int main()
{
    string a;
    cin>>a;
    int num=1;
    string num_str;
    num_str="";
    char c=a[0];
    for(int i=1;i<(int)a.size();i++)
    {
        if(!isNum(a[i]))
        {
            num=num_str.empty()?1:stoll(num_str);
            for(int j=0;j<num;j++)
                cout<<c;
            c=a[i];
            num=1;
            num_str.clear();
        }
        else
            num_str.push_back(a[i]);
    }
    num=num_str.empty()?1:stoll(num_str);
    for(int i=0;i<num;i++)
        cout<<c;
    return 0;
}