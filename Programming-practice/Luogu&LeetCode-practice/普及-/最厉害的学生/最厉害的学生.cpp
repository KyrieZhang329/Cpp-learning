#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct stu{
    string name;
    int index;
    int chi;
    int math;
    int eng;
    int sum;
};

int main()
{
    int n;
    cin>>n;
    vector<stu> v(n);
    for(int i=0;i<n;i++)
    {
        v[i].index=i;
        cin>>v[i].name>>v[i].chi>>v[i].math>>v[i].eng;
        v[i].sum=v[i].chi+v[i].math+v[i].eng;
    }
    int max=v[0].sum;
    int record=0;
    for(const stu& i:v)
    {
        if(i.sum>max)
        {
            max=i.sum;
            record=i.index;
        }
    }
    cout<<v[record].name<<" "<<v[record].chi<<" "<<v[record].math<<" "<<v[record].eng;
    return 0;
    
}