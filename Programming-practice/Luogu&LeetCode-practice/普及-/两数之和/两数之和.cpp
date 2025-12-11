#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) 
        cin >> nums[i];
    unordered_set<int> sum_set;
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            if (i != j) 
                sum_set.insert(nums[i] + nums[j]);
        }
    }

    int count = 0;
    for (int num : nums) 
    {
        if (sum_set.count(num)) 
            count++;
    }
    cout<<count;
    return 0;
}