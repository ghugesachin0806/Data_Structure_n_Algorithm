// https://leetcode.com/problems/target-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findWays(vector<int> &num, int tar)
    {
        int curr_index = num.size() - 1;

        // Memoization vector
        vector<vector<int>> dp(num.size(), vector<int>(tar + 1, 0));

        dp[0][0] = 1;

        if (num[0] <= tar)
            dp[0][num[0]] = 1;

        if (num[0] == 0)
            dp[0][num[0]] = 2;

        for (int i = 1; i < num.size(); i++)
        {
            for (int del = 0; del <= tar; del++)
            {
                // Exclude call
                int excl = dp[i - 1][del];

                // Include call
                int incl = 0;
                if (del - num[i] >= 0)
                    incl = dp[i - 1][del - num[i]];

                dp[i][del] = incl + excl;
            }
        }

        return dp[num.size() - 1][tar];
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        int total_sum = 0;

        for (auto it : nums)
            total_sum = total_sum + it;

        if (total_sum - target < 0 || ((total_sum - target) % 2 == 1))
            return 0;

        int tar = (total_sum - target) / 2;
        return findWays(nums, tar);
    }
};