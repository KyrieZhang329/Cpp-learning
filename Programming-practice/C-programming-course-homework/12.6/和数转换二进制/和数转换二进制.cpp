#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int size=(int)s.size();
    vector<int> v(size);
    for(int i=0;i<size;i++)
        v[i]=s[i]-'0';
    int num=accumulate(v.begin(),v.end(),0);
    string result="";
    if(num==0)
        cout<<0;
    while(num)
    {
        result+=to_string(num%2);
        num/=2;
    }
    
    reverse(result.begin(),result.end());
    cout<<result;
    return 0;
}