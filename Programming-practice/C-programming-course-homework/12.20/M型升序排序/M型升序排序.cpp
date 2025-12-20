#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    vector<int> v(m*n);
    for(int& i:v)
        cin>>i;
    vector<vector<int> > result(m,vector<int>(n));
    sort(v.begin(),v.end());
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        vector<int> temp(m);
        for(int j=0;j<m;j++)
            temp[j]=v[cnt++];
        if(i%2==0)
            reverse(temp.begin(),temp.end());
        for(int j=0;j<m;j++)
            result[j][i]=temp[j];
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

