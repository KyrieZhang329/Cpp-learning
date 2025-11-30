#include<iostream>
using namespace std;

int main()
{
    int arr[14]={-5,9,11,13,32,4,1,10,88,2,8,3,16,14};
    int size=sizeof(arr)/sizeof(arr[0]);
    int boundary=size-1;
    bool swapped;
    for(int i=0;i<size-1;i++) 
    {
        swapped=false;
        int newBoundary=0;
        for(int j=1;j<=boundary;j++) 
        {
            if (arr[j-1]>arr[j]) 
            { 
                int temp=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=temp;
                swapped=true;
                newBoundary=j;
            }
        }
        if (!swapped) 
            break; 
        boundary=newBoundary; 
    }
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";   
    return 0;
}