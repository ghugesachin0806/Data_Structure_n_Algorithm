// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, bool buy_flag, vector<int> &prices, vector<vector<int>> &dp)
    {

        if (index == prices.size())
            return 0;

        if (dp[index][buy_flag] != -1)
            return dp[index][buy_flag];

        // Not yet bought / buy allowed
        if (buy_flag == false)
        {
            int buy = solve(index + 1, true, prices, dp) - prices[index];
            int skip = solve(index + 1, false, prices, dp) + 0;

            return dp[index][buy_flag] = max(buy, skip);
        }

        // Already bought / sell allowed
        else
        {
            int sell = solve(index + 1, false, prices, dp) + prices[index];
            int skip = solve(index + 1, true, prices, dp) + 0;

            return dp[index][buy_flag] = max(sell, skip);
        }
    }
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));

        return solve(0, false, prices, dp);
    }
};