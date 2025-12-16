#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(const string& a, const string & b)
{
    return a.size()>b.size();
}

int main()
{
    string str;
    getline(cin,str);
    vector<string> v;
    string current_word;
    current_word="";
    for(const char& i:str)
    {
        if(i!=' '&&i!='.')
            current_word.push_back(i);
        else
        {
            v.push_back(current_word);
            current_word.clear();
        }
    }
    sort(v.begin(),v.end(),cmp);
    cout<<v[0].size();
    return 0;
}