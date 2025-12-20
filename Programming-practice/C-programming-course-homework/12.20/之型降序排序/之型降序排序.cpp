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
    sort(v.begin(),v.end(),[](int a,int b){return a>b;});
    vector<vector<int> > result(m,vector<int>(n));
    int cnt=0;
    for(vector<int>& i:result)
    {
        for(int& j:i)
            j=v[cnt++];
    }
    for(int i=1;i<result.size();i+=2)
        reverse(result[i].begin(),result[i].end());
    for(const vector<int>& i:result)
    {
        for(const int& j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}