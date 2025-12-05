#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

void SelectionSort(vector<int>& arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
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
}

void BucketSort(vector<int>& v)
{
    int max_val=*max_element(v.begin(),v.end());
    int min_val=*min_element(v.begin(),v.end());
    int bucket_count=(int)v.size();
    vector<vector<int> > buckets(bucket_count);
    for(int i=0;i<bucket_count;i++)
    {
        int index=static_cast<int>((v[i]-min_val)/(max_val-min_val+1)*bucket_count);
        buckets[index].push_back(v[i]);
    }
    int result_index=0;
    for(int i=0;i<(int)buckets.size();i++)
    {
        if(!buckets[i].empty())
            SelectionSort(buckets[i],(int)buckets[i].size());
            //这里建议也可以使用stl库中的sort进行桶内部排序，更加方便
        for(int j=0;j<(int)buckets[i].size();j++)
            v[i++]=buckets[i][j];
    }
}

int main()
{
    vector<int> v{11280,2037,1028,387,2917,-938};
    BucketSort(v);
    for(int i:v)
        cout<<i;
    return 0;
}