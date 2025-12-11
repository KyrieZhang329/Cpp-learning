#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int arr[3]={0};
    char str[101];
    cin.getline(str,101);
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {
        if((str[i]>='A'&&str[i]<='Z')||(str[i]>='a'&&str[i]<='z'))
            arr[0]++;
        else if(str[i]>='0'&&str[i]<='9')
            arr[1]++;
        else
            arr[2]++;
    }
    cout<<arr[0]<<' '<<arr[1]<<' '<<arr[2]<<' ';
}