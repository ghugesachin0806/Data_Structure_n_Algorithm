// https://leetcode.com/problems/coin-change/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        // Memoization vector
        vector<int> DP(amount + 1, INT_MAX);

        DP[0] = 0;
        if (amount == 0)
            return 0;

        // solve for every amount from 0 to Amount
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if ((i - coins[j] >= 0 && DP[i - coins[j]] != INT_MAX))
                    DP[i] = min(DP[i], 1 + DP[i - coins[j]]);
            }
        }

        if (DP[amount] == INT_MAX)
            return -1;

        return DP[amount];
    }
};