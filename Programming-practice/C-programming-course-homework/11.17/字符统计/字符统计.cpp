#include<iostream>
#include<cstring>
#include<limits>
using namespace std;

int main()
{
    int n,cnt=0;
    char c;
    char arr[100];
    cin>>c>>n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(arr,101);
    int len=strlen(arr);
    for(int i=0;i<len;i++)
    {
        if(n==0)
        {
            if(arr[i]==c||arr[i]==c-32||arr[i]==c+32)
                cnt++;
        }
        else
        {
            if(arr[i]==c)
                cnt++;
        }
    }
    cout<<cnt;
    return 0;
}