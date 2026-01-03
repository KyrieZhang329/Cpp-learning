#include<iostream>
#include<vector>
#include<numeric>
#include<cstdio>
using namespace std;

int dis(const int& n)
{
    if(n>300)
        return 6;
    else if(n>=201)
        return 5;
    else if(n>=151)
        return 4;
    else if(n>=101)
        return 3;
    else if(n>=51)
        return 2;
    else 
        return 1;
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    vector<int> cnt(6,0);
    for(int& i:v)
    {
        cin>>i;
        cnt[dis(i)-1]++;
    }
    double aver=accumulate(v.begin(),v.end(),0)/(n*1.0);
    printf("%.2f\n",aver);
    for(const int& i:cnt)
        cout<<i<<" ";
    return 0;
}