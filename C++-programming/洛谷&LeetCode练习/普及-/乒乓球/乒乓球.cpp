#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

int w,l;

void calculate(string str,int num)
{
    w=0;
    l=0;
    for(char i:str)
    {
        if(i=='W')
            w++;
        else if(i=='L')
            l++;
        if((w>=num||l>=num)&&abs(w-l)>=2)
        {
            cout<<w<<':'<<l<<endl;
            w=0;
            l=0;
        }
    }
    cout<<w<<':'<<l<<endl;
}

int main()
{
    string str;
    char x;
    while(cin>>x)
    {
        if(x=='E')
            break;
        else
            str+=x;
    }
    calculate(str,11);
    cout<<endl;
    calculate(str,21);
    return 0;
}