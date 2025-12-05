#include<iostream>
#include<vector>
using namespace std;

void MergeSort(vector<int>& arr) 
{
    int n=arr.size();
    vector<int> temp(n);
    for (int width=1;width<n;width=2*width) 
    {
        for (int left=0;left<n;left+=2*width) 
        {
            int mid=min(left+width-1,n-1);
            int right=min(left+2*width-1,n-1);
            if (mid<right) 
            {
                int i=left,j=mid+1,k=left;
                while(i<=mid&&j<=right) 
                {
                    if(arr[i]<=arr[j]) 
                        temp[k++]=arr[i++];
                    else
                        temp[k++]=arr[j++];
                }
                while(i<=mid) 
                    temp[k++]=arr[i++];
                while(j<=right) 
                    temp[k++]=arr[j++];
                for(int idx=left;idx<=right;idx++) 
                    arr[idx]=temp[idx];
            }
        }
    }
}

int main()
{

}