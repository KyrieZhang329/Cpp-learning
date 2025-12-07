#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int HoarePartition(vector<int>& v,int start,int end)
{
    int pivot=v[start];
    int i=start-1;
    int j=end+1;
    while(i<j)
    {
        do i++;
        while(v[i]<pivot);
        do j--;
        while(v[j]>pivot);
        if(!(i>=j))
            swap(v[i],v[j]);
    }
    return j;
}

void QuickSort(vector<int>& v,int start,int end)
{
    if(start<end)
    {
        int pivot=HoarePartition(v,start,end);
        QuickSort(v,start,pivot);
        QuickSort(v,pivot+1,end);
    }
}

int main()
{
    vector<int> v={29,3948,298,-99,8374,-7773,947,2};
    QuickSort(v,0,v.size()-1);
    for(int i:v)
        cout<<i<<" ";
    return 0;
}