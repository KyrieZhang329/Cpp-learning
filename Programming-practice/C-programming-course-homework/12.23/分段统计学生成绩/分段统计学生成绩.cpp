#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<pair<string,int> > v(n);
    for(auto& i:v)
        cin>>i.first>>i.second;
    vector<int> num(3);
    for(const auto& i:v)
    {
        if(i.second<=100&&i.second>=80)
            num[0]++;
        else if(i.second>=60&&i.second<=79)
            num[1]++;
        else
            num[2]++;
    }
    for(const int& i:num)
        cout<<i<<" ";
    return 0;
}