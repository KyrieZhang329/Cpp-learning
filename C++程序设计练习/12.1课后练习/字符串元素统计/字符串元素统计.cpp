#include<iostream>
#include<string>
using namespace std;

void output(string s);

int main()
{
    string str;
    cin>>str;
    output(str);
    return 0;
}

void output(string s)
{
    int num=0,cha=0;
    for(int i:s)
    {
        if((i>='a'&&i<='z')||(i>='A'&&i<='Z'))
            cha++;
        else if(i>='0'&&i<='9')
            num++;
    }
    cout<<cha<<','<<num;
}