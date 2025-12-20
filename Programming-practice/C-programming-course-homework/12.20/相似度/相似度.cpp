#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_set>
#include<iomanip>
#include<cctype>
using namespace std;

void to_lower(string& str)
{
    for(size_t i = 0; i < str.size(); i++)
        str[i] = tolower(str[i]);
}

int main()
{
    string a,b;
    getline(cin,a);
    getline(cin,b);
    to_lower(a);
    to_lower(b);
    string short_str=(a.size()<=b.size())?a:b;
    string long_str=(a.size()<=b.size())?b:a;
    unordered_set<string> st;
    for(int i=0;i<short_str.size();i++)
    {
        for(int j=i;j<short_str.size();j++)
            st.insert(short_str.substr(i,j-i+1));
    }
    int L=0;
    for(int i=0;i<long_str.size();i++)
    {
        for(int j=i;j<long_str.size();j++)
        {
            string current=long_str.substr(i,j-i+1);
            if(st.count(current))
                L=max(L,static_cast<int>(current.size()));
        }
    }
    double total_len=static_cast<double>(a.size()+b.size());
    double sim=2.0*L/total_len;
    cout<<fixed<<setprecision(3)<<sim;
    return 0;
}