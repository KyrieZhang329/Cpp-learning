#include<iostream>
using namespace std;

void InsertionSort(int* arr,int n)
{
    for(int i=1;i<n;i++)
    {
        int index=arr[i];
        int left=0;
        int right=i-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(arr[mid]>index)
                right=mid-1;
            else
                left=mid+1;
        }
        for(int j=i-1;j>=left;j--)
            arr[j+1]=arr[j];
        arr[left]=index;
    }
}

int main()
{
    int arr[10]={9,8,7,6,5,4,3,2,1,0};
    int size=sizeof(arr)/sizeof(arr[0]);
    InsertionSort(arr,size);
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
}