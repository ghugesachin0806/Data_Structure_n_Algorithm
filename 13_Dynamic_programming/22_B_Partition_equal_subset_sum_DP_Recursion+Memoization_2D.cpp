// https://leetcode.com/problems/partition-equal-subset-sum/

// https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(int index, int sum, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (sum == 0)
            return true;

        if (index < 0 || sum < 0)
            return false;

        if (dp[index][sum] != -1)
            return dp[index][sum];

        // Include call
        bool b1 = solve(index - 1, sum - nums[index], nums, dp);

        // Exclude call
        bool b2 = solve(index - 1, sum, nums, dp);

        dp[index][sum] = (b1 || b2);

        return dp[index][sum];
    }

    bool canPartition(vector<int> &nums)
    {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];
        }

        if (sum % 2 != 0)
            return false;

        // Memoization vector
        vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, -1));

        int index = nums.size() - 1;

        return solve(index, sum / 2, nums, dp);
    }
};