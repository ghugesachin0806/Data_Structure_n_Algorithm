// https://leetcode.com/problems/partition-equal-subset-sum/

// https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];
        }

        if (sum % 2 != 0 || nums.size() == 1)
            return false;

        // Memoization vector
        vector<vector<bool>> dp(nums.size(), vector<bool>(sum + 1, false));

        for (int i = 0; i < nums.size(); i++)
            dp[i][0] = true;

        dp[0][nums[0]] = true;

        for (int i = 1; i < nums.size(); i++)
        {
            for (int del = 0; del <= (sum / 2); del++)
            {
                // Exclude call
                bool b1 = dp[i - 1][del];

                // Include call
                bool b2 = false;
                if (del - nums[i] >= 0)
                {
                    b2 = dp[i - 1][del - nums[i]];
                }

                dp[i][del] = (b1 || b2);
            }
        }

        return dp[nums.size() - 1][sum / 2];
    }
};