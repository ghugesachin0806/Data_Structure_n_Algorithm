// https://leetcode.com/problems/min-cost-climbing-stairs/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        // Memoization vector
        vector<int> DP(n + 1, -1);

        // Assign the values to Base case
        // if n == base values return it
        DP[0] = cost[0];
        if (n == 0)
            return cost[0];

        DP[1] = cost[1];

        for (int i = 2; i <= n; i++)
        {
            DP[i] = min(DP[i - 1], DP[i - 2]);

            if (i != n)
                DP[i] = DP[i] + cost[i];
        }

        return DP[n];
    }
};