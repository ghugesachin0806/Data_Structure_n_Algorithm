// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, bool buy_flag, int trans, vector<int> &prices)
    {
        if (trans == 0 || index == prices.size())
            return 0;

        // Not yet bought / buy allowed
        if (buy_flag == false)
        {
            int buy = solve(index + 1, true, trans, prices) - prices[index];
            int skip = solve(index + 1, buy_flag, trans, prices) + 0;

            return max(buy, skip);
        }
        // Already bought / sell allowed
        else
        {
            int sell = solve(index + 1, false, trans - 1, prices) + prices[index];
            int skip = solve(index + 1, buy_flag, trans, prices) + 0;

            return max(sell, skip);
        }
    }
    int maxProfit(vector<int> &prices)
    {
        int trans_limit = 2;

        return solve(0, false, trans_limit, prices);
    }
};