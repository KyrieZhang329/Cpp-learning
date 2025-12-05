#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int& i:v)
        cin>>i;
    sort(v.begin(),v.end());
    auto last=unique(v.begin(),v.end());
    v.erase(last,v.end());
    cout<<(int)v.size()<<endl;
    for(int i:v)
        cout<<i<<" ";
    return 0;
}