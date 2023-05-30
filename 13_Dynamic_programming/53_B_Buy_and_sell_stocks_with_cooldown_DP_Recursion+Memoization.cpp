// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, bool buy_flag, int cool_down, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if (index == prices.size())
            return 0;

        if (dp[index][cool_down][buy_flag] != -1)
            return dp[index][cool_down][buy_flag];

        // Not yet bought / buy allowed
        if (buy_flag == false)
        {
            if (cool_down)
            {
                int buy = solve(index + 1, true, cool_down, prices, dp) - prices[index];
                int skip = solve(index + 1, false, cool_down, prices, dp) + 0;

                return dp[index][cool_down][buy_flag] = max(buy, skip);
            }
            else
            {
                int skip = solve(index + 1, false, true, prices, dp) + 0;
                return dp[index][cool_down][buy_flag] = skip;
            }
        }

        // Already bought / sell allowed
        else
        {
            int sell = solve(index + 1, false, false, prices, dp) + prices[index];
            int skip = solve(index + 1, true, cool_down, prices, dp) + 0;

            return dp[index][cool_down][buy_flag] = max(sell, skip);
        }
    }
    int maxProfit(vector<int> &prices)
    {
        int cool_down = true;
        vector<vector<vector<int>>> dp(prices.size() + 1, vector(2, vector<int>(2, -1)));
        return solve(0, false, cool_down, prices, dp);
    }
};