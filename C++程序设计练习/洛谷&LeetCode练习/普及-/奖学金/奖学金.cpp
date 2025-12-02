#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct stu{
    int num;
    int chi;
    int math;
    int eng;
    int total;
};

bool cmp(const stu& s,const stu& t);

int main()
{
    int n;
    cin>>n;
    vector<stu> v(n);
    int cnt=1;
    for(stu& i:v)
    {
        i.num=cnt++;
        cin>>i.chi>>i.math>>i.eng;
        i.total=i.chi+i.math+i.eng;
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<5;i++)
        cout<<v[i].num<<" "<<v[i].total<<endl;
    return 0;
}

bool cmp(const stu& s,const stu& t)
{
    if(s.total==t.total)
    {
        if(s.chi==t.chi)
            return s.num<t.num;
        return s.chi>t.chi;
    }
    return s.total>t.total;
}
    