#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool isPrime(int num) 
{
    if (num<2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for(int i=3; i*i<=num; i+=2) 
    {
        if (num%i==0) 
            return false;
    }
    return true;
}

void backtrack(vector<int>& nums, int start, int k, int currentSum, int& count) 
{
    if (k == 0) 
    {
        if (isPrime(currentSum)) 
            count++;
        return;
    }
    for (int i = start; i <= nums.size() - k; i++) 
        backtrack(nums, i + 1, k - 1, currentSum + nums[i], count);
}

int main() 
{
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for (int i=0;i<n;i++) 
        cin >> nums[i];
    int count=0;
    backtrack(nums,0,k,0,count);
    cout<<count;
    return 0;
}