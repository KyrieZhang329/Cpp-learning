#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int LomutoPartition(vector<int>& v,int start,int end)
{
    int pivot=v[end];
    int i=start;
    for(int j=start;j<end;j++)
    {
        if(v[j]<=pivot)
        {
            swap(v[i],v[j]);
            i++;
        }
    }
    swap(v[i],v[end]);
    return i;
}

void QuickSort(vector<int>& v,int start,int end)
{
    if(start<end)
    {
        int pivot=LomutoPartition(v,start,end);
        QuickSort(v,start,pivot-1);
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