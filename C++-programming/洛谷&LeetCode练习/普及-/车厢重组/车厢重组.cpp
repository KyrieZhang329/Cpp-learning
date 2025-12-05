#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int BubbleSort(vector<int>& v);

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int& i:v)
        cin>>i;
    int num=BubbleSort(v);
    cout<<num;
    return 0;
}

int BubbleSort(vector<int>& v)
{
    int num=0;
    int boundary=(int)v.size()-1;
    bool swapped;
    for(int i=0;i<(int)v.size()-1;i++)
    {
        int newboundary=0;
        swapped=false;
        for(int j=1;j<=boundary;j++)
        {
            if(v[j-1]>v[j])
            {
                swap(v[j-1],v[j]);
                newboundary=j;
                swapped=true;
                num++;
            }
        }
        if(!swapped)
            break;
        boundary=newboundary;
    }
    return num;
}