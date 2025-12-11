#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;

struct stu{
    string name;
    int chi;
    int math;
    int eng;
    int total;
};

bool cmp(stu& a,stu& b){
    return a.name<b.name;
}

int main()
{
    int n;
    cin>>n;
    vector<stu> v(n);
    for(stu& i:v)
    {
        cin>>i.name>>i.chi>>i.math>>i.eng;
        i.total=i.chi+i.math+i.eng;
    }
    vector<pair<string,string> > name_pair;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(abs(v[i].total-v[j].total)<=10)
            {
                if(abs(v[i].chi-v[j].chi)<=5&&abs(v[i].math-v[j].math)<=5&&abs(v[i].eng-v[j].eng)<=5)
                {
                    string min_name=min(v[i].name,v[j].name);
                    string max_name=max(v[i].name,v[j].name);
                    name_pair.push_back(make_pair(min_name,max_name));
                }
            }
        }
    }
    for(pair<string,string>& i:name_pair)
        cout<<i.first<<" "<<i.second<<endl;
    return 0;
}