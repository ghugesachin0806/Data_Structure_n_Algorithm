// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, bool buy_flag, int cool_down, vector<int> &prices)
    {
        if (index == prices.size())
            return 0;

        // Not yet bought / buy allowed
        if (buy_flag == false)
        {
            if (cool_down)
            {
                int buy = solve(index + 1, true, cool_down, prices) - prices[index];
                int skip = solve(index + 1, false, cool_down, prices) + 0;

                return max(buy, skip);
            }
            else
            {
                int skip = solve(index + 1, false, true, prices) + 0;
                return skip;
            }
        }

        // Already bought / sell allowed
        else
        {
            int sell = solve(index + 1, false, false, prices) + prices[index];
            int skip = solve(index + 1, true, cool_down, prices) + 0;

            return max(sell, skip);
        }
    }
    int maxProfit(vector<int> &prices)
    {
        int cool_down = true;
        return solve(0, false, cool_down, prices);
    }
};