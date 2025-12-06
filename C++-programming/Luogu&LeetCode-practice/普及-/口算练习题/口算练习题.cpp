#include<iostream>
#include<string>
#include<vector>
#include<cctype> 
using namespace std;

struct index{
    char cha;
    int num1;
    int num2;
    int result;
};

int main()
{
    int n;
    cin>>n;
    vector<index> v(n);
    char last_op; 
    for (int i=0;i<n;i++) 
    {
        cin>>ws;
        if(isalpha(cin.peek())) 
        {
            cin>>v[i].cha>>v[i].num1>>v[i].num2;
            last_op=v[i].cha;
        } 
        else 
        {
            v[i].cha=last_op;
            cin>>v[i].num1>>v[i].num2;
        }
    }
    for(int i=0;i<n;i++)
    {
        char op_char;
        switch(v[i].cha)
        {
            case 'a':
                op_char='+';
                v[i].result=v[i].num1+v[i].num2;
                break;
            case 'b':
                op_char='-';
                v[i].result=v[i].num1-v[i].num2;
                break;
            case 'c':
                op_char='*';
                v[i].result=v[i].num1*v[i].num2;
                break;
        }
        string str;
        str =to_string(v[i].num1)+op_char+to_string(v[i].num2)+'='+ to_string(v[i].result);
        cout<<str<<endl<<str.size()<<endl;
    }
    return 0;
}