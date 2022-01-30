#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        vector<int>v;
        for(auto it:nums){
            int x=stoi(it);
            v.push_back(x);
        }
        sort(nums.begin(),nums.end());
        int n=v.size();
        string ans= nums[n-k]; 
        
        return ans;
    }
};