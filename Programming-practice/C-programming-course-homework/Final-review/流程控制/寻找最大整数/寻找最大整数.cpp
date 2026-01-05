#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> v(4);
    for(int& i:v)
        cin>>i;
    sort(v.begin(),v.end());
    cout<<v[3];
    return 0;
}