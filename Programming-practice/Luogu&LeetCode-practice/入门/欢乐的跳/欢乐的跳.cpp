#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[1050];
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr[i]=a;
    }
    int diff[1051];
    int cnt=0;
    for(int i=0;i<n-1;i++)
    {
        int index=arr[i+1]-arr[i];
        if(index>=0)
            diff[i]=index;
        else
            diff[i]=(-1)*index;
    }
    for(int i=1;i<=n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(diff[j]==i)
            {
                cnt++;
            }
        }
    }
    if(cnt==n-1)
    {
        cout<<"Jolly"<<endl;
    }
    else
    {
        cout<<"Not jolly"<<endl;
    }
    return 0;
}
