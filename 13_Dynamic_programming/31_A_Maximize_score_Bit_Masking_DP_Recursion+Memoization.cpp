// https://leetcode.com/problems/maximize-score-after-n-operations/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int curr_op, int mask, vector<int> &nums, vector<int> &dp)
    {
        if (curr_op >= nums.size() / 2)
            return 0;

        if (dp[mask] != -1)
            return dp[mask];

        int max_score = INT_MIN;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if ((mask >> i) & 1 == 1)
                continue;

            for (int j = i + 1; j < nums.size(); j++)
            {
                if ((mask >> j) & 1 == 1)
                    continue;

                int new_mask = (mask | (1 << i) | (1 << j));

                int curr_score = (curr_op + 1) * __gcd(nums[i], nums[j]);
                int remaining_score = solve(curr_op + 1, new_mask, nums, dp);
                max_score = max(max_score, curr_score + remaining_score);
            }
        }

        dp[mask] = max_score;
        return dp[mask];
    }

    int maxScore(vector<int> &nums)
    {
        int m = nums.size();
        int dp_size = 1 << m; // 2^m

        vector<int> dp(dp_size, -1);

        int curr_op = 0;
        int mask = 0;

        return solve(curr_op, mask, nums, dp);
    }
};