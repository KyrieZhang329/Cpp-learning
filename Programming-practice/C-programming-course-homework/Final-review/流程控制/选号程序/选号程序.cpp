#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int& i:v)
        cin>>i;
    sort(v.begin(),v.end(),[](const int& a,const int& b)->bool {
        string str_a=to_string(a);
        string str_b=to_string(b);
        int sum_a=0,sum_b=0;
        for(const int& i:str_a)
            sum_a+=i-'0';
        for(const int& i:str_b)
            sum_b+=i-'0';
        if(sum_a!=sum_b)
            return sum_a>sum_b;
        return a>b; 
    });
    cout<<v[0];
    return 0;
}