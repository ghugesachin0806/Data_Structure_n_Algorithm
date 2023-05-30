// https://leetcode.com/problems/longest-increasing-subsequence/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, int prev, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (index == nums.size())
            return 0;

        if (dp[index][prev + 1] != -1)
            return dp[index][prev + 1];

        if (prev == -1 || nums[index] > nums[prev])
        {
            // Include call
            int incl = solve(index + 1, index, nums, dp) + 1;

            // Exclude call
            int excl = solve(index + 1, prev, nums, dp) + 0;

            return dp[index][prev + 1] = max(incl, excl);
        }
        else
        {
            // Exclude call
            return dp[index][prev + 1] = solve(index + 1, prev, nums, dp);
        }
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int prev = -1;

        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));

        return solve(0, prev, nums, dp);
    }
};