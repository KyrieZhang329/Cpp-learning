#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

struct group{
    string name;
    int num;
    int points;
};

int main()
{
    int n;
    cin>>n;
    vector<group> v(n);
    for(group& i:v)
        cin>>i.name;
    vector<vector<int> > point(n,vector<int>(n));
    for(vector<int>& i:point)
    {
        for(int& j:i)
            cin>>j;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            switch(point[i][j])
            {
                case 5:
                    v[i].points+=2;
                    v[j].points++;
                    v[i].num++;
                    break;
                case -5:
                    v[j].points+=2;
                    v[i].points++;
                    v[j].num++;
                    break;
                case 3:
                    v[i].points+=3;
                    v[i].num++;
                    break;
                case 4:
                    v[i].points+=3;
                    v[i].num++;
                    break;
                default:
                    v[j].points+=3;
                    v[j].num++;
                    break;
            }
        }
    }
    sort(v.begin(),v.end(),[](const group& a,const group& b){
        if(a.num==b.num)
        {
            if(a.points==b.points)
                return a.name<b.name;
            return a.points>b.points;
        }
        return a.num>b.num;
    });
    for(const group& i:v)
        cout<<i.name<<" "<<i.num<<" "<<i.points<<endl;
    return 0;
}