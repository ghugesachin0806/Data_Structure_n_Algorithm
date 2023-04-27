// https://leetcode.com/problems/coin-change/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &coins, int amount)
{
    if (amount == 0)
        return 0;

    if (amount < 0)
        return INT_MAX;

    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int ans = solve(coins, amount - coins[i]);
        if (ans != INT_MAX)
            mini = min(mini, ans + 1);
    }

    return mini;
}

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int mini = solve(coins, amount);

        if (mini == INT_MAX)
            return -1;

        return mini;
    }
};