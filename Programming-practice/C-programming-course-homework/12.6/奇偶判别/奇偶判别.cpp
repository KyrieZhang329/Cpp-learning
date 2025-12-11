#include<iostream>
#include<string>
#include<numeric>
#include<vector>
using namespace std;

int main()
{
    string s;
    cin>>s;
    vector<int> v(s.size());
    int size=(int)s.size();
    int index=0;
    for(int i=0;i<size;i++)   
        v[i]=s[i]-'0';
    int sum=accumulate(v.begin(),v.end(),0);
    if(sum%2==0)
        index=1;
    cout<<size<<" "<<sum<<" "<<index;
}