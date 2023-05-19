// https://leetcode.com/problems/coin-change-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (index < 0)
        {
            if (amount == 0)
                return 1;
            else
                return 0;
        }

        if (dp[index][amount] != -1)
            return dp[index][amount];

        // Include current index
        int temp1 = 0;
        if (amount >= coins[index])
            temp1 = solve(index, amount - coins[index], coins, dp);

        // Exclude current index
        int temp2 = solve(index - 1, amount, coins, dp);

        dp[index][amount] = temp1 + temp2;

        return dp[index][amount];
    }
    int change(int amount, vector<int> &coins)
    {
        int curr_index = coins.size() - 1;

        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
        return solve(curr_index, amount, coins, dp);
    }
};