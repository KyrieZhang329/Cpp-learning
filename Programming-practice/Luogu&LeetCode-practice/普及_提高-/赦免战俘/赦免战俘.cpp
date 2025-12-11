#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

void fun(vector<vector<bool> >&v,int row,int col,int len);

int main()
{
    int n;
    cin>>n;
    int k=1<<n;
    vector<vector<bool> > v(k,vector<bool>(k,true)); 
    fun(v,0,0,k); 
    stringstream ss;
    for (vector<bool> i:v) 
    {
        for (bool j:i) 
        {
            ss<<(j?1:0)<<" ";
        }
        ss<<"\n";
    }
    cout<<ss.str();
    return 0;
}

void fun(vector<vector<bool> >& v,int row,int col,int len)
{
    if (len==1) 
        return;
    int mid=len/2;
    for (int i=row;i<row+mid;i++) 
    {
        for (int j=col;j<col+mid;j++) 
            v[i][j] = false;
    }
    fun(v,row,col+mid,mid); 
    fun(v,row+mid,col,mid);
    fun(v,row+mid,col+mid,mid);
}
