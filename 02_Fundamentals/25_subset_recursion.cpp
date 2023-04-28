// https://leetcode.com/problems/subsets/

// Subsets in recursion

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int index, vector<int> &nums, vector<vector<int>> &ans, vector<int> temp)
    {
        if (index >= nums.size())
        {
            ans.push_back(temp);
            return;
        }

        // Exclude call
        solve(index + 1, nums, ans, temp);

        // Include call
        temp.push_back(nums[index]);
        solve(index + 1, nums, ans, temp);
        
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int index = 0;

        vector<int> temp;
        vector<vector<int>> ans;

        solve(index, nums, ans, temp);

        return ans;
    }
};