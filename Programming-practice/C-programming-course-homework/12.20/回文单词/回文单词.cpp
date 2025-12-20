#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    string str;
    cin>>str;
    string re_str=str;
    reverse(re_str.begin(),re_str.end());
    vector<string> v={"gni","de","yl","re","s"};
    for(const string& i:v)
    {
        if(re_str.find(i,0)==0)
        {
            str.erase(str.end()-i.size(),str.end());
            re_str.erase(re_str.begin(),re_str.begin()+i.size());
            break;
        }
    }
    cout<<str<<endl;
    if(str==re_str)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}