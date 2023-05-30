// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, bool buy_flag, int trans, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if (trans == 0 || index == prices.size())
            return 0;

        if (dp[index][trans][buy_flag] != -1)
            return dp[index][trans][buy_flag];

        // Not yet bought / buy allowed
        if (buy_flag == false)
        {
            int buy = solve(index + 1, true, trans, prices, dp) - prices[index];
            int skip = solve(index + 1, buy_flag, trans, prices, dp) + 0;

            return dp[index][trans][buy_flag] = max(buy, skip);
        }
        // Already bought / sell allowed
        else
        {
            int sell = solve(index + 1, false, trans - 1, prices, dp) + prices[index];
            int skip = solve(index + 1, buy_flag, trans, prices, dp) + 0;

            return dp[index][trans][buy_flag] = max(sell, skip);
        }
    }
    int maxProfit(vector<int> &prices)
    {
        int trans_limit = 2;

        vector<vector<vector<int>>> dp(prices.size() + 1, vector(3, vector<int>(2, -1)));

        return solve(0, false, trans_limit, prices, dp);
    }
};