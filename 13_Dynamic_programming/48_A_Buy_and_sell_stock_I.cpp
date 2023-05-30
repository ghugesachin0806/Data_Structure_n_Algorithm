// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mini = prices[0];
        int profit = INT_MIN;

        for (int i = 1; i < prices.size(); i++)
        {
            int temp_profit = prices[i] - mini;
            profit = max(profit, temp_profit);
            mini = min(mini, prices[i]);
        }

        if (profit > 0)
            return profit;
        else
            return 0;
    }
};