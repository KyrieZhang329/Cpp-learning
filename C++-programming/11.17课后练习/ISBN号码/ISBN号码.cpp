#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char arr[14];
    cin.getline(arr,14);
    int index=1;
    int sum=0;
    int len = strlen(arr);
    for(int i=0;i<len-1;i++)
    {
        if(arr[i]=='-')
            continue;
        else
        {
            sum+=(arr[i]-'0')*index;
            index++;
        }    
    }   
    if(sum%11==(arr[len-1]-'0')||(sum%11==10&&arr[len-1]=='X'))
        cout<<"Right";
    else
    {
        if(sum%11==10)
            arr[len-1]='X';
        else
            arr[len-1]=sum%11+'0';
        for(int i=0;i<len;i++)
            cout<<arr[i];
    }
    return 0;
}