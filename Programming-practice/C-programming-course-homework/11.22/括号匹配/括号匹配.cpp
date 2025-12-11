#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int main()
{
    char arr[51];
    cin.getline(arr,51);
    vector<char> v;
    int len=strlen(arr);
    for(int i=0;i<len;i++)
    {
        if(arr[i]=='('||arr[i]==')'||arr[i]=='{'||arr[i]=='}'||arr[i]=='['||arr[i]==']')
            v.push_back(arr[i]);
    } 
    if(v.size()%2!=0)   
        cout<<"no";
    else
    {
        bool is_match=true;
        vector<char> stack;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]=='('||v[i]=='['||v[i]=='{')
                stack.push_back(v[i]);
            else
            {
                if(stack.empty())
                {
                    is_match=false;
                    break;
                }
                else
                {
                    char c=stack.back();
                    stack.pop_back();
                    if( (v[i]==')'&&c!='(')||(v[i]=='}'&&c!='{')||(v[i]==']'&&c!='['))
                    {
                        is_match = false;
                        break;
                    }
                }
            }
        }
        if(is_match&&stack.empty())
            cout<<"yes";
        else
            cout<<"no";
    }
    return 0;
}