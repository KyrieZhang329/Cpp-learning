#include<iostream>
#include<vector>
using namespace std;

//合并
void Merge(vector<int>& v,int left,int mid,int right)
{
    vector<int> temp(right-left+1);
    int i=left;
    int j=right;
    int k=0;
    while(i<mid&&j<right)
    {
        if(v[i]<v[j])
            temp[k++]=v[i++];
        else
            temp[k++]=v[j++];
    }
    while(i<=mid)
        temp[k++]=v[i++];
    while(j<=right)
        temp[k++]=v[j++];
    for(int i=0;i<right-left+1;i++)
        v[i]=temp[i];
}
//递归进行合并排序
void MergeSort(vector<int>& v,int left,int right)
{
    int mid=left+(right-left)/2;
    MergeSort(v,left,mid);
    MergeSort(v,mid+1,right);
    Merge(v,left,mid,right);
}
//简化调用接口
void MergeSort(vector<int>& v)
{
    if(!v.empty())
        MergeSort(v,0,v.size()-1);
}

int main()
{
    vector<int> v{101,11,13,51,7,12,1,8,10,2,17,3,16,14};
    MergeSort(v);
    for(int i:v)
        cout<<i<<" ";
}