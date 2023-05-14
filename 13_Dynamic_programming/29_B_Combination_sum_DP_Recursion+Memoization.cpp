// https://leetcode.com/problems/combination-sum-iv/

// https://www.codingninjas.com/codestudio/problems/number-of-ways_3755252

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int target, vector<int> &nums, vector<int> &dp)
    {
        if (target == 0)
            return 1;
        if (target < 0)
            return 0;

        if (dp[target] != -1)
            return dp[target];

        int temp_sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            temp_sum = temp_sum + solve(target - nums[i], nums,dp);
        }
        
        dp[target] = temp_sum;

        return dp[target];
    }
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1, -1);
        return solve(target, nums, dp);
    }
};