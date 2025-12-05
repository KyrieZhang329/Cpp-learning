#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void CountingSort(vector<int>& v)
{
    int max_val=*max_element(v.begin(),v.end());
    int min_val=*min_element(v.begin(),v.end());

    vector<int> count(max_val-min_val+1,0);
    for(int i:v)
        count[i]++;
    
    for(int i=1;i<(int)count.size();i++)
        count[i]+=count[i-1];
    
    vector<int> output((int)v.size());
    for(int i=v.size()-1;i>=0;i--)
    {
        int current_val=v[i];
        output[count[current_val]-1]=current_val;
        count[current_val]--;
    }
    v=output;
}

int main()
{
    vector<int> v{9,11,13,4,67,12,-1,33,9,3};
    CountingSort(v);
    for(int i:v)
        cout<<i;
    return 0;
}
