#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    vector<int> v;
    while(n)
    {
        v.push_back(n%10);
        n/=10;
    }
    int sum=accumulate(v.begin(),v.end(),0);
    cout<<sum;
    return 0;
}