#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
using namespace std;

bool cmp(const pair<string,int>& a,const pair<string,int>& b)
{
    if(a.second!=b.second)
        return a.second>b.second;
    return a.first<b.first;
}

void Tolower(string &s)
{
    for(char&c:s)
        c=tolower(c);
}

int main()
{
    int n;
    cin>>n;
    vector<string> v(n);
    vector<pair<string,int> > record;
    for(int i=0;i<n;i++)   
    {
        cin>>v.at(i);
        Tolower(v.at(i));
    }
    char x;
    cin>>x;
    if(x>'A'&&x<'Z')
        x=x+32;
    for(int i=0;i<v.size();i++)
    {
        const string& s = v.at(i);
        if(s[0]==x)
        {
            if(record.empty())
                record.push_back(make_pair(v.at(i),1));
            else
            {
                bool found=0;
                for(int j=0;j<record.size();j++)
                {
                    if(v.at(i)==record.at(j).first)
                    {
                        record.at(j).second++;
                        found=1;
                        break;
                    }
                }
                if(!found)
                    record.push_back(make_pair(v.at(i),1));
            }
        }
    }
    sort(record.begin(),record.end(),cmp);
    int cnt=min(5,(int)(record.size()));
    for(int i=0;i<cnt;i++)
        cout<<record.at(i).first<<" ";
    return 0;
}