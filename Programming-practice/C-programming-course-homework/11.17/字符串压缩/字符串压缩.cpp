#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char arr[51]={'0'};
    cin.getline(arr,51);
    int index = strlen(arr);
    for(int i=0;i<index;i++)
    {
        char x=arr[i];
        int num=0;
        while(arr[i+1]>='0'&&arr[i+1]<='9')
        {
            num=num*10+(arr[i+1]-'0');
            i++;
        }
        if(num==0)
            cout<<x;
        else
        {
            for(int j=0;j<num;j++)
                cout<<x;
        }
    }
    return 0;
}
