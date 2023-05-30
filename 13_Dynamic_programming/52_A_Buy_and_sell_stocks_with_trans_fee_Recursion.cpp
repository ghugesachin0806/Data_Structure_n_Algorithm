// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, int buy_flag, int &fee, vector<int> &prices)
    {
        if (index == prices.size())
            return 0;

        // Not yet bought / buy allowed
        if (buy_flag == false)
        {
            int buy = solve(index + 1, true, fee, prices) - prices[index];
            int skip = solve(index + 1, false, fee, prices) + 0;

            return max(buy, skip);
        }

        // Already bought / sell allowed
        else
        {
            int sell = solve(index + 1, false, fee, prices) + prices[index] - fee;
            int skip = solve(index + 1, true, fee, prices) + 0;

            return max(sell, skip);
        }
    }
    int maxProfit(vector<int> &prices, int fee)
    {
        return solve(0, false, fee, prices);
    }
};