// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, bool buy_flag, vector<int> &prices)
    {

        if (index == prices.size())
            return 0;

        // Not yet bought / buy allowed
        if (buy_flag == false)
        {
            int buy = solve(index + 1, true, prices) - prices[index];
            int skip = solve(index + 1, false, prices) + 0;

            return max(buy, skip);
        }

        // Already bought / sell allowed
        else
        {
            int sell = solve(index + 1, false, prices) + prices[index];
            int skip = solve(index + 1, true, prices) + 0;

            return max(sell, skip);
        }
    }
    int maxProfit(vector<int> &prices)
    {
        return solve(0, false, prices);
    }
};