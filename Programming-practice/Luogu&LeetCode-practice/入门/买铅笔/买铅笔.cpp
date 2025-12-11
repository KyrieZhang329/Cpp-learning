#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

struct pencil{
    int count;
    int price;
};

int main()
{
    int n;
    cin>>n;
    vector<pencil> v(3);
    for(int i=0;i<3;i++)
        cin>>v[i].count>>v[i].price;
    int mini=INT_MAX;
     for(int i = 0; i < 3; i++)
    {
        int need_box = (n + v[i].count - 1) / v[i].count;
        int total = need_box * v[i].price;
        mini = min(mini, total);
    }
    cout<<mini;
    return 0;
}