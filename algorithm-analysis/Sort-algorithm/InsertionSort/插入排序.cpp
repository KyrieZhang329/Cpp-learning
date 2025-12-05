#include<iostream>
using namespace std;

void InsertionSort(int*arr,int n)
{
    for(int i=1;i<n;i++)
    {
        int index=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>index) 
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=index;
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
