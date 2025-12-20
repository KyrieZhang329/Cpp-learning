#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str;
    cin>>str;
    auto it=str.begin()+1;
    for(const char& i:str)
        it=str.insert(it,' ')+2;
    cout<<str;
    return 0;
}