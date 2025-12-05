#include<iostream>
using namespace std;

int main(void)
{
    int arr[10];
    for(int i=0;i<7;i++)
    {
        int a,b;
        cin>>a>>b;
        arr[i]=a+b;
    }
    int index=0;
    int result=0;
    for(int i=0;i<7;i++)
    {
        if(arr[i]>8)
        {
            index=1;
            if(arr[i]>arr[result])
            {
                result=i;
            }
        }
    }
    int r=result+1;
    if(index==0)
        cout<<0<<endl;
    else if(index==1)
        cout<<r<<endl;
    return 0;
}