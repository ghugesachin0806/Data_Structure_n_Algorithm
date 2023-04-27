// https://leetcode.com/problems/min-cost-climbing-stairs/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();

        // Assign the values to Base case
        // if n == base values return it
        int curr;
        int prev1 = cost[0];
        if (n == 0)
            return prev1;

        int prev2 = cost[1];

        for (int i = 2; i <= n; i++)
        {
            curr = min(prev1, prev2);
            if (i != n)
                curr = curr + cost[i];

            prev1 = prev2;
            prev2 = curr;
        }

        return prev2;
    }
};