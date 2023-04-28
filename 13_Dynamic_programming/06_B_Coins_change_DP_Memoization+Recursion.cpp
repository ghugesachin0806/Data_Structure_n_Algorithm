// https://leetcode.com/problems/coin-change/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &coins, int amount, vector<int> &DP)
{
    if (amount == 0)
        return 0;

    if (amount < 0)
        return INT_MAX;

    if (DP[amount] != -1)
        return DP[amount];

    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int ans = solve(coins, amount - coins[i], DP);
        if (ans != INT_MAX)
            mini = min(mini, ans + 1);
    }

    DP[amount] = mini;
    return mini;
}

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        // Memoization vector
        vector<int> DP(amount + 1, -1);
        int mini = solve(coins, amount, DP);

        if (mini == INT_MAX)
            return -1;

        return mini;
    }
};