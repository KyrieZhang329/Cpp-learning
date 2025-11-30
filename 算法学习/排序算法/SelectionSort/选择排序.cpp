#include<iostream>
using namespace std;

int main()
{
    int arr[16]={9,11,13,4,6,5,7,12,1,10,15,2,8,3,16,14};
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size-1;i++)
    {
        int min=i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[min])
                min=j;
        }
        if(min!=i)
        {
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    return 0;
}