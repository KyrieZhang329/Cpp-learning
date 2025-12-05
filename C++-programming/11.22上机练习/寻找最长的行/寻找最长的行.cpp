#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;

int main()
{
    vector<pair<string,int> > v;
    while(1)
    {
        char cstr[101];
        cin.getline(cstr,101);
        if(strcmp(cstr,"***end***")==0)
            break;
        v.push_back(make_pair(cstr,strlen(cstr)));
    }
    int cnt=v[0].second;
    string max=v[0].first;
    for(int i=0;i<v.size();i++)
    {
        if(v[i].first.size()>max.size())
        {
            cnt=v[i].second;
            max=v[i].first;
        }
    }
    cout<<cnt<<endl<<max;
    return 0;
}