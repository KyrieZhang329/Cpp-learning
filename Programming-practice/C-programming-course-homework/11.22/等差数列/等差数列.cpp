#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort(v.begin(),v.end());
    bool index=1;
    for(int i=1;i<v.size()-1;i++)
    {
        if(v[i]-v[i-1]!=v[i+1]-v[i])
        {
            index=0;
            break;
        }
    }
    if(!index)
        cout<<"no";
    else
        cout<<v[1]-v[0];
    return 0;
}