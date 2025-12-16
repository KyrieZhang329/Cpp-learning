#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str;
    getline(cin,str);
    bool index=true;
    for(int i=0;i<(int)str.size()/2;i++)
    {
        if(str[i]!=str[(int)str.size()-i-1])
        {    
            index=false;
            break;
        }
    }
    if(index)
        cout<<"yes";
    else
        cout<<"no";
    return 0;
}